# Speller
CS-50 week 5 problem set


### About the problem
         စာအုပ်တစ်အုပ်ထဲက စာလုံးတွေကို dictionaryနဲ့တိုက်စစ်ပြီး စာလုံးပေါင်းမှန်လားတိုက်စစ်ရန် 
         
         
### What to do?
        To write 5 functions

            1.Load function

            2.Hash function

            3.Size function

            4.Check function

            5.Unload function
            
### Structure of file for problem
          
          1. Speller.c (main function)
          
          2. Dictionary (the function that we have to write)
          
          3. Dictionary.h (define all the global value)
          
          4. Dictionary folder (where contain dictionary)
          
          5. Text folder    (where contain the file to be spell checked)
          
### Overview of the problem
          
                                          ./speller [dict] text
                                                      /      \
                                             တိုက်စစ်မယ့်file    အစစ်ခံရမယ့် file 
                                                /               \
                                    upload to memory            fopen()
                                    with load() function          \
                                            /                 Word တစ်လုံးချင်းစီကို array အဖြစ်လုပ်ပြီး
                                          /                   သက်ဆိုင်ရာ charလေးတွေထည့် (inside the speller.c)
                             by using hash()                         \
              store the word into hash table                     word array တစ်ခုချင်းစီကို check() ထဲထည့်ပြီး 
                                      /                          စာလုံးပေါင်းစစ်
                        close the dictionary
                        with unload()
          

### 1.Load() function
            Take the dictionary file as input. Put every words of dictionary into hash table.
            Return true when every word has been put.
            
            step1 - Open Dictionary
            
            step2 - Read Each Word From File 
            
            step3 - Add these word into hash table with the aid of hash function
            
            
### 2.Hash() function
            To return index which tell where to add the word node into hash table. 
            That index must be smaller than the hash table array length.
            
             ### In hash function we have to use an algorithm how to put the word in hash table
                        then I use a simple hash function
                          
### 2.1.Hash algorithm
           စာလုံးတစ်လုံးကို Hash table ထဲကိုဘယ်လိုနည်းနဲ့ထည့်ရမလဲဆိုတာကိုစဉ်းစားရမယ်။ There are a lot of algorithm for this but mine is
           
           Cat -> c a t -> 99 + 97 + 116 -> 312 %  36 ->       0   
                    |       |   |     |      |     |           |
                  tolower     to ASCII      SUM   length      remainder
                                                    of 
                                                 hash table
                                                 
                                                 
            --------So the word Cat must be put at the  0 index of hash table array-------
            
            When there is collision (same index but different word),use link list(see the code)
            
            Afther all we will get the index 0 and use it in load funciton
            
            
### 3.Size function
            To return number of words from dictionary that have been added into hash table
            
### 4.Check function
            Take the text file as input. To check the word of text file with dictionary's word.
            
### 5.Unload function
            To free all the memoray that we have been allocated into the hash table.
            
### Note
            Hash Table is just an array with link list in it's node.
            
            To know more about hash algorithm watch this youtube video.
                 https://youtu.be/KyUTuwz_b7Q

