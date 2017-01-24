---
title: "Literais num&#233;ricas, boolianas e de ponteiro (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "constantes, literais"
  - "literais"
  - "literais, C++"
ms.assetid: 17c09fc3-3ad7-47e2-8b48-ba8ae994edc8
caps.latest.revision: 16
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Literais num&#233;ricas, boolianas e de ponteiro (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um literal é um elemento de programa que representa um valor diretamente.  Este artigo aborda os literais do tipo inteiro, ponto flutuante, boolean e ponteiro.  Para obter informações sobre a cadeia de caracteres e caracteres literais, consulte[cadeia de caracteres e caracteres literais \(C\+\+\)](../cpp/string-and-character-literals-cpp.md).  Você também pode definir seus próprios literais com base em qualquer uma dessas categorias; Para obter mais informações, consulte[literais definidos pelo usuário \(C\+\+\)](../Topic/User-Defined%20Literals%20%20\(C++\).md)  
  
 .  Você pode usar literais em muitos contextos, mas a maioria comumente para inicializar variáveis nomeadas e passar argumentos para funções:  
  
```  
const int answer = 42; // integer literal  
double d = sin(108.87);     //floating point literal passed to sin function  
bool b = true;              // boolean literal  
MyClass* mc = nullptr;      // pointer literal  
  
```  
  
 Às vezes, é importante dizer ao compilador como interpretar um literal ou tipo específico para dar a ele.  Para fazer isso, acrescentando prefixos ou sufixos para o literal.  Por exemplo, o prefixo 0 x instrui o compilador a interpretar o número seguinte como um valor hexadecimal, por exemplo 0x35.  O sufixo BTER instrui o compilador a tratar o valor como um`unsigned long long`tipo, como 5894345ULL.  Consulte as seções a seguir para obter uma lista de prefixos e sufixos para cada tipo de literal.  
  
## Sintaxe  
  
## Literais inteiros  
 Literais inteiros começam com um dígito e não tem nenhuma parte fracionária ou expoente.  Você pode especificar literais inteiro em formato decimal, octal ou hexadecimal.  Elas podem especificar tipos com sinal e sem sinal e longos ou curtos.  
  
 Quando nenhum prefixo ou sufixo estiver presente, o compilador fornecerá um tipo de valor literal inteiro`int`\(32 bits\), se ajustará o valor, caso contrário, ele irá atribuir a ela tipo`long long`\(64 bits\).  
  
 Para especificar um literal inteiro decimal, inicie a especificação com um dígito diferente de zero.  Por exemplo:  
  
```  
int i = 157;   // Decimal literal  
int j = 0198;       // Not a decimal number; erroneous octal literal  
int k = 0365;       // Leading zero specifies octal literal, not decimal  
int m = 36'000'000  // digit separators make large values more readable  
int   
```  
  
 Para especificar um literal inteiro octal, inicie a especificação com 0, seguido por uma sequência de dígitos no intervalo de 0 a 7.  Os dígitos 8 e 9 são erros na especificação de um literal octal.  Por exemplo:  
  
```  
int i = 0377;   // Octal literal  
int j = 0397;        // Error: 9 is not an octal digit  
```  
  
 Para especificar um literal inteiro hexadecimal, inicie a especificação com`0x`ou`0X`\(no caso do "x" não importa\), seguido por uma sequência de dígitos no intervalo`0`por meio de`9`e`a`\(ou`A`\) por meio de`f`\(ou`F`\).  Os dígitos hexadecimais de `a` \(ou `A`\) a `f` \(ou `F`\) representam valores no intervalo de 10 a 15.  Por exemplo:  
  
```  
int i = 0x3fff;   // Hexadecimal literal  
int j = 0X3FFF;        // Equal to i  
```  
  
 Para especificar um tipo sem sinal, use o sufixo **u** ou **U**.  Para especificar um tipo longo, use o sufixo **l** ou **L**.  Para especificar um tipo integral de 64 bits, use o LL ou sufixo ll.  O sufixo i64 ainda tem suporte, mas deve ser evitado porque ele é específico da Microsoft e não é portátil.  Por exemplo:  
  
```  
unsigned val_1 = 328u;             // Unsigned value  
long val_2 = 0x7FFFFFL;                 // Long value specified   
                                        //  as hex literal  
unsigned long val_3 = 0776745ul;        // Unsigned long value  
auto val_4 = 108LL;                           // signed long long  
auto val_4 = 0x8000000000000000ULL << 16;     // unsigned long long   
```  
  
 **Separadores de dígito**: você pode usar o caractere de aspas simples \(apóstrofo\) para separar os valores de local em um número maior para facilitar para os humanos ler.  Separadores não têm nenhum efeito na compilação.  
  
```  
long long i = 24'847'458'121  
```  
  
## Literais de ponto flutuante  
 Literais de ponto flutuante especificam valores que devem ter uma parte fracionária.  Esses valores contêm pontos decimais \(**.**\) e podem conter expoentes.  
  
 Literais de ponto flutuante têm uma "mantissa", que especifica o valor do número, um "expoente", que especifica a magnitude do número, e um sufixo opcional que especifica o tipo literal.  A mantissa é especificada como uma sequência de dígitos seguida por um ponto final, seguidos por uma sequência opcional de dígitos que representa a parte fracionária do número.  Por exemplo:  
  
```  
18.46  
38.  
```  
  
 O expoente, se presente, especifica a magnitude do número como uma potência de 10, como mostrado no seguinte exemplo:  
  
```  
18.46e0      // 18.46  
18.46e1           // 184.6  
```  
  
 O expoente pode ser especificado usando **e** ou **E**, que têm o mesmo significado, seguido por um sinal opcional \(\+ ou \-\) ou uma sequência de dígitos.  Se um expoente estiver presente, o ponto decimal à direita é desnecessário em números inteiros como `18E0`.  
  
 Literais de ponto flutuante padrão para o tipo**duplo**.  Usando os sufixos**f**ou**l**\(ou**F**ou**L**— o sufixo não diferencia maiúsculas de minúsculas\), o literal pode ser especificado como**float**ou`long double`respectivamente.  
  
 Embora `long double` e **double** tenham a mesma representação, eles não têm o mesmo tipo.  Por exemplo, você pode ter funções sobrecarregadas como  
  
```  
void func( double );  
```  
  
 e  
  
```  
void func( long double );  
```  
  
## Literais boolianos  
 Literais booleanos são`true`e`false`.  
  
## Ponteiro literal \(C \+ \+ 11\)  
 C\+\+ apresenta o[nullptr](../Topic/nullptr.md)literal para especificar um ponteiro inicializada do zero.  No código portátil,`nullptr`deve ser usado em vez do tipo integral zero ou macros, como NULL.  
  
## Literais binários \(C \+ \+ 14\)  
 Um literal binário pode ser especificado com o uso da`0B`ou`0b`prefixo, seguido por uma seqüência de 1 e 0:  
  
```  
  
auto x = 0B001101 ; // int  
auto y = 0b000001 ; // int  
```  
  
## Evite usar literais como "constantes mágicas"  
 Embora nem sempre é uma boa prática de programação, você pode usar literais diretamente em expressões e instruções:  
  
```  
if (num < 100)  
    return "Success";  
  
```  
  
 No exemplo anterior, talvez seja melhor usar uma constante nomeada que transmita um significado claro, por exemplo "MAXIMUM\_ERROR\_THRESHOLD".  E se o valor de retorno "Êxito" é visto pelos usuários finais, então talvez seja melhor usar uma constante de seqüência nomeada de caracteres que pode ser armazenada em um único local em um arquivo de onde ele pode ser localizado em outros idiomas.  Usando constantes nomeadas ajuda a outras pessoas, bem como para entender a intenção do código.  
  
## Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)   
 [constantes de inteiro C\+\+](http://msdn.microsoft.com/pt-br/1f3b58a4-8346-4533-ba6e-df26d76f8dcf)   
 [literais de caracteres C\+\+](http://msdn.microsoft.com/pt-br/a7901c61-524d-47c6-beb6-d9dacc2e72ed)   
 [constantes de ponto flutuante C\+\+](http://msdn.microsoft.com/pt-br/f6273f24-a876-4484-a7a2-e82275692ad3)   
 [literais de cadeia de caracteres C\+\+](../cpp/string-and-character-literals-cpp.md)   
 [literais definidos pelo usuário do C\+\+](../Topic/User-Defined%20Literals%20%20\(C++\).md)