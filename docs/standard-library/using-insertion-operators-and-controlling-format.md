---
title: "Usando operadores de inser&#231;&#227;o e controlando o formato | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "operadores de inserção"
ms.assetid: cdefe986-6548-4cd1-8a67-b431d7d36a1c
caps.latest.revision: 8
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando operadores de inser&#231;&#227;o e controlando o formato
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico mostra como controlar o formato e como criar operadores de inserção de suas próprias classes.  A inserção \(**\<\<**\) operador, que é previamente programada para todos os tipos de dados padrão do C\+\+, envia bytes para um objeto de fluxo de saída.  Operadores de inserção trabalham com predefinido "manipuladores," que são elementos que alterar o formato padrão dos argumentos inteiros.  
  
 Você pode controlar o formato com as seguintes opções:  
  
-   [Largura da saída](#vclrfoutputwidthanchor3)  
  
-   [Alinhamento](#vclrfalignmentanchor4)  
  
-   [Precisão](#vclrfprecisionanchor5)  
  
-   [Base](#vclrfradixanchor6)  
  
##  <a name="vclrfoutputwidthanchor3"></a> Largura da saída  
 Para alinhar a saída, você deve especificar a largura da saída para cada item, colocando o `setw` manipulador no fluxo de dados ou chamando o **largura** função de membro.  Este exemplo alinha à direita os valores em uma ampla de caracteres de coluna pelo menos 10:  
  
```  
// output_width.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main( )  
{  
   double values[] = { 1.23, 35.36, 653.7, 4358.24 };  
   for( int i = 0; i < 4; i++ )  
   {  
      cout.width(10);  
      cout << values[i] << '\n';  
   }  
}  
```  
  
### Saída  
  
```  
   1.23  
  35.36  
  653.7  
4358.24  
```  
  
 Os espaços em branco são adicionados como qualquer valor menos de 10 caracteres de largura.  
  
 Para acrescentar um campo, use o **preenchimento** a função de membro, que define o valor do caractere de preenchimento para campos que têm uma largura especificada.  O padrão é um espaço em branco.  Para preencher a coluna de números com asteriscos, modificar anterior **para** loop da seguinte maneira:  
  
```  
for( int i = 0; i < 4; i++ )  
{  
   cout.width( 10 );  
   cout.fill( '*' );  
   cout << values[i] << endl;  
}  
```  
  
 O `endl` manipulador substitui o caractere de nova linha \(`'\n'`\).  O resultado terá a seguinte aparência:  
  
```  
******1.23  
*****35.36  
*****653.7  
***4358.24  
```  
  
 Para especificar as larguras de elementos de dados na mesma linha, use o `setw` manipulador:  
  
```  
// setw.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <iomanip>  
using namespace std;  
  
int main( )  
{  
   double values[] = { 1.23, 35.36, 653.7, 4358.24 };  
   char *names[] = { "Zoot", "Jimmy", "Al", "Stan" };  
   for( int i = 0; i < 4; i++ )  
      cout << setw( 6 )  << names[i]  
           << setw( 10 ) << values[i] << endl;  
}  
```  
  
### Saída  
 O **largura** função de membro é declarada em \< iostream \>.  Se você usar `setw` ou qualquer outro manipulador com argumentos, você deve incluir \< iomanip \>.  Na saída, cadeias de caracteres são impressas em um campo de largura 6 e inteiros em um campo de largura 10:  
  
```  
 Zoot      1.23  
Jimmy     35.36  
   Al     653.7  
 Stan   4358.24  
```  
  
 Nem `setw` nem **largura** trunca valores.  Se a saída formatada excede a largura, a imprime o valor inteiro, sujeitos a definição da precisão do fluxo.  Ambos `setw` e **largura** afetam somente o campo a seguir.  Largura do campo será revertido para seu comportamento padrão \(a largura necessária\) depois de um campo foi impresso.  No entanto, as outras opções de formato de fluxo permanecem em vigor até que seja alterado.  
  
##  <a name="vclrfalignmentanchor4"></a> Alinhamento  
 Os fluxos de saída padrão para o texto alinhado à direita.  Para alinhar à esquerda os nomes no exemplo anterior e alinhar os números à direita, substitua o **para** loop da seguinte maneira:  
  
```  
for ( int i = 0; i < 4; i++ )  
   cout << setiosflags( ios::left )  
        << setw( 6 )  << names[i]  
        << resetiosflags( ios::left )  
        << setw( 10 ) << values[i] << endl;  
```  
  
 O resultado terá a seguinte aparência:  
  
```  
Zoot        1.23  
Jimmy      35.36  
Al         653.7  
Stan     4358.24  
```  
  
 O sinalizador left\-align é definido usando o [setiosflags](../Topic/setiosflags.md) manipulador com a [esquerda](../Topic/left.md) enumerador.  Este enumerador é definido na [ios](../Topic/ios.md) classe, para sua referência deve incluir o **ios::** prefixo.  O [resetiosflags](../Topic/resetiosflags.md) manipulador desativa o sinalizador left\-align.  Ao contrário de **largura** e `setw`, o efeito de `setiosflags` e `resetiosflags` é permanente.  
  
##  <a name="vclrfprecisionanchor5"></a> Precisão  
 O valor padrão para precisão de ponto flutuante é seis.  Por exemplo, o número 3466.9768 imprime como 3466.98.  Para alterar a maneira que imprime esse valor, use o [setprecision](../Topic/setprecision.md) manipulador.  O manipulador tem dois sinalizadores: [fixo](../Topic/fixed.md) e [científica](../Topic/scientific.md).  Se [fixo](../Topic/fixed.md) for definida, o número impresso como 3466.976800.  Se **científica** estiver definido, ele será impresso como 3.4669773 \+ 003.  
  
 Para exibir os números de ponto flutuante mostrados na [alinhamento](#vclrfalignmentanchor4) com um dígito significativo, substitua o **para** loop da seguinte maneira:  
  
```  
for ( int i = 0; i < 4; i++ )  
   cout << setiosflags( ios::left )  
        << setw( 6 )    
        << names[i]  
        << resetiosflags( ios::left )  
        << setw( 10 )   
        << setprecision( 1 )  
        << values[i]   
        << endl;  
```  
  
 O programa imprime nesta lista:  
  
```  
Zoot          1  
Jimmy     4e+001  
Al        7e+002  
Stan      4e+003  
```  
  
 Para eliminar a notação científica, inserir essa instrução antes do **para** loop:  
  
```  
cout << setiosflags( ios::fixed );  
```  
  
 Com a notação fixa, o programa imprime com um dígito após o ponto decimal.  
  
```  
Zoot         1.2  
Jimmy       35.4  
Al         653.7  
Stan      4358.2  
```  
  
 Se você alterar o **ios::fixed** sinalizar **ios::scientific**, o programa imprime isso:  
  
```  
Zoot    1.2e+000  
Jimmy   3.5e+001  
Al      6.5e+002  
Stan    4.4e+003  
```  
  
 Novamente, o programa imprime um dígito após o ponto decimal.  Se qualquer um dos **ios::fixed** ou **ios::scientific** estiver definido, o valor de precisão determina o número de dígitos após o ponto decimal.  Se nenhum sinalizador estiver definido, o valor de precisão determina o número total de dígitos significativos.  O `resetiosflags` manipulador limpa esses sinalizadores.  
  
##  <a name="vclrfradixanchor6"></a> Base  
 O **dec**, **oct**, e **hexadecimal** manipuladores de definir a base padrão para entrada e saída.  Por exemplo, se você inserir o **hexadecimal** manipulador no fluxo de saída, o objeto corretamente converte a representação interna dos dados de inteiros em um formato de saída hexadecimal.  Os números são exibidos com dígitos à f em minúsculas se o [maiúscula](../Topic/uppercase.md) sinalizador é Limpar \(padrão\); caso contrário, eles são exibidos em letras maiúsculas.  A base padrão é **dec** \(decimal\).  
  
## Cadeias de caracteres entre aspas \(C \+ \+ 14\)  
 Quando você insere uma cadeia de caracteres em um fluxo, você pode recuperar facilmente a mesma cadeia de caracteres chamando a função de membro stringstream::str\(\).  No entanto, se você quiser usar o operador de extração para inserir o fluxo em uma nova cadeia de caracteres em um momento posterior, você receberá um resultado inesperado porque o \>\> operador por padrão será interrompido quando encontra o primeiro caractere de espaço em branco.  
  
```  
  
std::stringstream ss;  
std::string inserted = "This is a sentence.";  
std::string extracted;  
  
ss << inserted;  
ss >> extracted;  
  
std::cout << inserted;     //  This is a sentence.  
std::cout << extracted;   //   This  
```  
  
 Esse comportamento pode ser superado manualmente, mas fazer o ciclo completo de cadeia de caracteres mais conveniente, C \+ \+ 14 adiciona o `std::quoted` transmitir manipulador em `<iomanip>`.  Após a inserção, `quoted()` envolve a cadeia de caracteres com um delimitador \(aspas duplas ' "' por padrão\) e após a extração manipula o fluxo para extrair todos os caracteres até encontrar o delimitador final.  Quaisquer aspas inseridas são ignoradas com um caractere de escape \("\\ \\ ' por padrão\).  
  
 Os delimitadores estão presentes apenas no objeto de fluxo; não estiverem presentes na cadeia de caracteres extraída mas estiverem presentes na cadeia de caracteres retornada por [basic\_stringstream::str](../Topic/basic_stringstream::str.md)\(\).  
  
 O comportamento de espaço em branco das operações de inserção e extração é independente de como uma cadeia de caracteres é representada no código, portanto, o operador entre aspas é útil, independentemente se a cadeia de caracteres de entrada é uma cadeia de caracteres bruta literal ou uma cadeia de caracteres regular.  A cadeia de entrada, seja qual for seu formato, pode ter inserido guias, quebras de linha, aspas e assim por diante e todos esses serão preservados, o manipulador quoted\(\).  
  
 Para obter mais informações e exemplos de código completo, consulte [entre aspas](../Topic/quoted.md).  
  
## Consulte também  
 [Fluxos de Saída](../standard-library/output-streams.md)   
 [entre aspas](../Topic/quoted.md)