class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vectors for prefix and suffix product arrays
        vector<int> prefix_products(nums.begin(), nums.end());
        vector<int> suffix_products(nums.begin(), nums.end());
        // calculate the products
        for (int i = 0; i < prefix_products.size() - 1; ++i) {
            prefix_products[i + 1] = prefix_products[i] * prefix_products[i + 1];
        }
        for (int i = suffix_products.size() - 1; i > 0; --i) {
            suffix_products[i - 1] = suffix_products[i] * suffix_products[i - 1];
        }
        // populate the output array, where output[i] is the product of all elements
        // of nums excepts nums[i] itself, by multiplying the prefix product to the left
        // with the suffix product to the right
        vector<int> output;
        for (int i = 0; i < nums.size(); ++i) {
            int left_product; int right_product;
            if (i == 0) {
                left_product = 1;
                right_product = suffix_products[i + 1];
            } else if (i == nums.size() - 1) {
                left_product = prefix_products[i - 1];
                right_product = 1;
            } else {
                left_product = prefix_products[i - 1];
                right_product = suffix_products[i + 1];
            }
            output.push_back(left_product * right_product);
        }
        return output;
    }
};
