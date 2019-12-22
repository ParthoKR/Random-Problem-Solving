/*
Author : Partho KR
Problem: Split an array into two subsets such that every subset contains equal sum.

This program has been implemented by backtracking.
*/
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
class Node{
    int i, currentSum, remainingSum;
    Node left = null, right = null, parent = null;
}
public class SplitArray {
    static boolean checker = false;
    static Node groot;
    static boolean shouldJump(Node node, int target){
        if((node.remainingSum == 0 && node.currentSum != 0) || node.currentSum > target || (node.left != null && node.right != null) || (node.currentSum + node.remainingSum) < target){
            return true;
        }else{
            return false;
        }
    }
    static void dfs(Node node, Integer[] nums, int target){
        if(node == groot){
            System.out.println("Called root");
        }
        if(node.currentSum == target){
            checker = true;
            return;
        }
        if((node.currentSum == 0 && node.remainingSum == 0) || (node == groot && node.left != null && node.right != null)){
            checker = false;
            return;
        }
        Node newNode = new Node();
        if(shouldJump(node, target)){
            newNode = node.parent;
        }else if(node.left == null && node.right == null){
            newNode.i = node.i + 1;
            newNode.currentSum = node.currentSum + nums[newNode.i];
            newNode.remainingSum = node.remainingSum - nums[newNode.i];
            newNode.parent = node;
            node.left = newNode;
            System.out.println("Current sum = " + newNode.currentSum + " Remaining sum = " + newNode.remainingSum + " i = " + newNode.i);
        }else if(node.left != null && node.right == null){
            newNode.i = node.i + 1;
            newNode.currentSum = node.currentSum;
            newNode.remainingSum = node.remainingSum - nums[newNode.i];
            newNode.parent = node;
            node.right = newNode;
            System.out.println("Current sum = " + newNode.currentSum + " Remaining sum = " + newNode.remainingSum + " i = " + newNode.i);
        }
        dfs(newNode, nums, target);
    }
    static boolean canPartition(Integer[] nums){
        int sum = 0;
        for(int i: nums){
            sum += i;
        }
        int target = sum/2;
        Node root = new Node();
        root.i = -1;
        root.currentSum = 0;
        root.remainingSum = sum;
        groot = root;
        if(sum%2 != 0){
            return false;
        }
        dfs(root, nums, target);
        return checker;
    }
    public static void main(String[] args){
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        Integer[] nums = new Integer[n+1];
        for(int i = 0; i<n; ++i){
            nums[i] = sc.nextInt();
        }
        nums[n] = 0;
        Arrays.sort(nums, Collections.reverseOrder());
        if(canPartition(nums)){
            System.out.println("Can");
        }else{
            System.out.println("Can't");
        }
    }
}
