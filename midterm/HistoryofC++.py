def read_in():
    words = []
    with open('HistoryofC++.txt') as file:
        for word in file:
            words.extend(word.split())
    return words

def display_words(words):
    print("Words stored in the buffer: ")
    for word in words:
        print(word)

def count_words(words):
    word_count = 0
    for word in words:
        word_count += 1
    return word_count

words = read_in()
display_words(words)
print(f"Number of words in the file: {count_words(words)}")



