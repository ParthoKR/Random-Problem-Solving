class Expression:
    def __init__(self, exp):
        self.exp = exp
        self.prec = {
            '^': 0,
            '/': 1,
            '*': 2,
            '+': 3,
            '-': 3,
        }
    def whole_operand(self, i, source=0):
        """
        source = 0 for substringifying from self.exp otherwise from self.postfix 
        returns a tuple of substring(whole number) and the last index of substring
        """
        k = i
        src_string = self.exp if source == 0 else self.postfix
        for j in range(i, len(src_string)):
            if(self.is_operand(src_string[j])):
                k = j
            else:
                break
        return (src_string[i:k+1], k)
    def get_corresponding_starting_parentesis(self, token):
        if token == ')':
            return '('
        elif token == '}':
            return '{'
        else:
            return '['

    def process_closing_parenthesis(self, stack, token):
        while(stack[-1] != self.get_corresponding_starting_parentesis(token)):
            self.postfix += stack[-1] + ' '
            stack.pop()
        stack.pop()

    def is_operand(self, c):
        return (c.isnumeric())
    
    def is_opening_parenthesis(self, c):
        return (c=='(' or c=='{' or c=='[') 
    
    def is_closing_parenthesis(self, c):
        return (c==')' or c=='}' or c==']') 


    def is_higher(self, a, b):
        """ higher precedence means lower value """
        return self.prec[a] < self.prec[b] 

    def to_postfix(self):
        stack = []
        self.postfix = ""
        i = 0
        while i < len(self.exp):
            c = self.exp[i]
            # if initial of token is a number then look for whole number
            if(self.is_operand(self.exp[i])):
                c = self.whole_operand(i)[0]
                i = self.whole_operand(i)[1] # update i with the index of next not null token
            if c == ' ':
                i += 1  # if current token is 
                        # white space advance token to the next one
                        #  by increasing index and continue
                continue 
            if self.is_opening_parenthesis(c):
                stack.append(c)
            elif self.is_closing_parenthesis(c):
                self.process_closing_parenthesis(stack, c)
            elif self.is_operand(c):
                self.postfix += c + ' '
            else:
                # when token is an operator
                # two cases may arise at the top of the stack
                # there may be any opening parenthesis or an operand
                if len(stack) > 0 and self.is_opening_parenthesis(stack[-1]):
                    # when top of stack contains opening parenthesis
                    stack.append(c)
                else:
                    # when top of stack contains an operand
                    while(len(stack) > 0 and self.is_higher(stack[-1], c)):
                        self.postfix += stack.pop() + ' '
                    # now top of stack should contain opening parenthesis of operator of less precedence
                    # push new token to the stack
                    stack.append(c)
            i += 1
        # stack may contain additional operators
        # pop them and add to postfix expression
        while(len(stack) > 0):
            self.postfix += stack.pop() + ' '
        return self.postfix
    def operate(self, a, b, c):
        if c == '+':
            return a + b
        elif c == '*':
            return a*b
        elif c == '-':
            return b-a
        elif c == '/':
            return b/a
        elif c == '^':
            return b**a
    def eval(self):
        stack = []
        i = 0
        while i < len(self.postfix):
            c = self.postfix[i]
            if(self.is_operand(c)):
                c = self.whole_operand(i, 1)[0]
                i = self.whole_operand(i, 1)[1]
                stack.append(int(c))
            elif c == ' ':
                i += 1
                continue
            else:
                # when current token is an operator
                a, b = stack.pop(), stack.pop() # pop the first two item from stack
                stack.append(self.operate(a, b, c)) # apply operator between the popped two
            i += 1
        return stack.pop() # now stack should contain only one element which is the final result
exp = Expression(input("Enter expression: "))
print(f"Postfix expression: {exp.to_postfix()}")
print(f"Evaluation: {exp.eval()}")
