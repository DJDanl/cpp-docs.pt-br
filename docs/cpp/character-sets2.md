---
title: "Conjuntos de caracteres | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
helpviewer_keywords: 
  - "Conjuntos de caracteres"
  - "conjunto de caracteres de origem básicos (C++)"
  - "nomes de caracteres universais"
  - "conjunto de caracteres de execução básico (C++)"
ms.assetid: 379a2af6-6422-425f-8352-ef0bca6c0d74
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjuntos de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O texto de um programa C\+\+ é armazenado em arquivos de origem que usam uma codificação de caracteres em particular. O padrão de C\+\+ especifica um caractere de origem básico definido para arquivos de origem e um caractere de execução básico definido para os arquivos compilados. Visual C\+\+ permite que um conjunto adicional de caracteres específica de localidade a ser usado nos arquivos de origem e arquivos compilados.  
  
## Conjuntos de caracteres  
 O C\+\+ padrão especifica um *conjunto de caracteres de origem básico* que podem ser usados nos arquivos de origem. Para representar caracteres fora deste conjunto, os caracteres adicionais podem ser especificados usando um *nome de caractere universais*. Quando compilada, a *conjunto de caracteres de execução básico* e *conjunto de caractere largo de execução básico* representam os caracteres e cadeias de caracteres que podem aparecer em um programa. A implementação do Visual C\+\+ permite caracteres adicionais no código\-fonte e código compilado.  
  
### Conjunto de caracteres de origem básico  
 O *conjunto de caracteres de origem básico* consiste em 96 caracteres que podem ser usados nos arquivos de origem. Esse conjunto inclui o caractere de espaço, tabulação horizontal, tabulação vertical, avanço e caracteres de controle de nova linha, e o conjunto de caracteres gráficos:  
  
 `a b c d e f g h i j k l m n o p q r s t u v w x y z`  
  
 `A B C D E F G H I J K L M N O P Q R S T U V W X Y Z`  
  
 `0 1 2 3 4 5 6 7 8 9`  
  
 `_ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " '`  
  
 **Específico da Microsoft**  
  
 O Visual C\+\+ inclui o `$` caractere como um membro do conjunto de caracteres de origem básico. Visual C\+\+ também permite que um conjunto de caracteres a ser usado nos arquivos de origem, com base na codificação do arquivo. Por padrão, o Visual Studio armazena arquivos de origem usando a página de código padrão. Quando os arquivos de origem são salvos usando uma página de código específica de localidade ou uma página de código Unicode, Visual C\+\+ permite que você use qualquer um dos caracteres da página de código em seu código\-fonte, exceto para os códigos de controle não explicitamente permitidos no caractere fonte básica definido. Por exemplo, você pode colocar caracteres japoneses em comentários, identificadores ou literais de cadeia de caracteres, se você salvar o arquivo usando uma página de código japonesa. Visual C\+\+ não permite seqüências de caracteres que não podem ser traduzidas em caracteres multibyte ou pontos de código Unicode. Dependendo das opções do compilador, permitidos todos os caracteres podem aparecer em identificadores. Para obter mais informações, consulte [Identificadores](../cpp/identifiers-cpp.md).  
  
 **FIM de específico da Microsoft**  
  
### Nomes de caracteres universais  
 Como programas C\+\+ podem usar vários outros caracteres daqueles especificados no conjunto de caracteres de origem básico, você pode especificar esses caracteres de uma forma transportável usando *nomes de caracteres universais*. Um nome de caractere universais consiste em uma seqüência de caracteres que representam um ponto de código Unicode.  Eles têm duas formas. Use `\UNNNNNNNN` para representar um ponto de código Unicode do formulário U \+ NNNNNNNN, onde NNNNNNNN é o número de ponto de código hexadecimal de oito dígitos. Use quatro dígitos `\uNNNN` para representar um ponto de código Unicode do formulário U \+ 0000NNNN.  
  
 Nomes de caracteres universais podem ser usados em identificadores e em literais de cadeia de caracteres e caracteres. Um nome de caracteres universais não pode ser usado para representar um ponto de código substituto no intervalo 0xD800 0xDFFF. Em vez disso, use o ponto de código desejada; o compilador gera automaticamente qualquer substitutos necessários. Restrições adicionais se aplicam aos nomes de caracteres universais podem ser usados em identificadores. Para obter mais informações, consulte [Identificadores](../cpp/identifiers-cpp.md) e [Literais de cadeia de caracteres e de caracteres](../cpp/string-and-character-literals-cpp.md).  
  
 **Específico da Microsoft**  
  
 O compilador do Visual C\+\+ trata um caractere no formulário de nome de caractere universais e formulário literal alternadamente. Por exemplo, você pode declarar um identificador com formato de nome de caractere universais e usá\-lo no formulário literal:  
  
```cpp  
auto \u30AD = 42; // \u30AD is 'キ' if (キ == 42) return true; // \u30AD and キ are the same to the compiler  
  
```  
  
 O formato de caracteres estendidos na área de transferência do Windows é específico para as configurações de localidade do aplicativo. Recortar e colar esses caracteres no código de outro aplicativo podem introduzir codificações de caractere inesperado. Isso pode resultar em erros de análise sem causa visível em seu código. É recomendável que você defina sua fonte codificação do arquivo para uma página de código Unicode antes de colar caracteres estendidos. Também recomendamos que você use um IME ou o aplicativo do mapa de caracteres para gerar caracteres estendidos.  
  
 **FIM de específico da Microsoft**  
  
### Conjunto de caracteres de execução básico  
 O *conjunto de caracteres de execução básico* e *conjunto de caractere largo de execução básico* consistem em todos os caracteres no conjunto de caracteres de origem básico e os caracteres de controle que representam o alerta, backspace, retorno de carro e o caractere nulo.   O *conjunto de caracteres de execução* e *conjunto de caractere largo de execução* são subconjuntos dos conjuntos básicos. Eles incluem os caracteres de origem definido pela implementação fora do conjunto de caracteres de origem básico. O conjunto de caracteres de execução tem uma representação específica de localidade.