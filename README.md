# project-example

C++項目的文件組織模板

## 各模塊説明

- core/ModuleName0: 最基本的格式
- core/ModuleName1: 用於PyWrap的示例類
- core/ModuleName2: 加了子模塊的格式
- core/PyWrap: 用於生成Python工具庫的模塊

## 命名規範説明

### 1. 變量

- 基本形式是**以下劃綫相隔**的**全小寫**單詞，除布爾變量外，都以**定語+名詞**的形式組成
    ```python
    blue_rose = 0
    ```
- 如果是**全局變量**就改成**全大寫**
    ```python
    BLUE_ROSE = 0
    ```
- 如果是**布爾變量**，就改成**狀態+flag**
    ```python
    active_flag = True
    ```
- 如果需要標號，就在定語+名詞后**以下劃綫隔開標號**，如果是臨時變量，并且可以只用**單個字母**命名，則標號前**不用加下劃綫**
    ```python
    blue_rose_1 = 0
    blue_rose_2 = 0
    x1 = 0
    y1 = 0
    ```
- 如果是**形參**，就加**前綴io_/in_/out_/init_**，分別代表輸入輸出/輸入/輸出/初始化
    ```python
    def missYou(io_blue_rose):
        io_blue_rose = None
        return io_blue_rose
    ```

### 2. 函數名

- 基本形式是**駝峰命名法**，以**動詞+名詞**的形式組成
    ```python
    missYou()
    ```
- 類的**方法名**同函數
    ```python
    my_mind.missYou()
    ```

### 3. 類名

- 基本形式**類似于駝峰命名法**，但**首字母也大寫**，以**定語+名詞**的形式組成，結構體的命名方式與類一致
    ```python
    my_mind = CrazyMind()
    ```

