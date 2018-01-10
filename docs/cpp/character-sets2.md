---
title: Caractere Sets2 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
helpviewer_keywords:
- Character sets
- basic source character set (C++)
- universal character names
- basic execution character set (C++)
ms.assetid: 379a2af6-6422-425f-8352-ef0bca6c0d74
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: db505809c1fbc2c49e116b9c2f850f6e14dfbdf6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="character-sets"></a>Conjuntos de caracteres
O texto de um programa C++ é armazenado em arquivos de origem que usam uma codificação de caracteres em particular. O padrão do C++ especifica um caractere de origem básicas definidas para arquivos de origem e um caractere de execução básico definidas para arquivos compilados. Visual C++ permite que um conjunto adicional de caracteres específicas da localidade a ser usado nos arquivos de origem e arquivos compilados.  
  
## <a name="character-sets"></a>Conjuntos de caracteres  
 O padrão do C++ especifica um *conjunto de caracteres de origem básico* que pode ser usado nos arquivos de origem. Para representar caracteres fora deste conjunto, os caracteres adicionais podem ser especificados usando um *nome de caractere universal*. Quando compilado, o *conjunto de caracteres de execução básico* e *conjunto de caracteres amplo de execução básico* representar os caracteres e cadeias de caracteres que podem aparecer em um programa. A implementação do Visual C++ permite caracteres adicionais no código-fonte e código compilado.  
  
### <a name="basic-source-character-set"></a>Conjunto de caracteres de origem básico  
 O *conjunto de caracteres de origem básico* consiste em 96 caracteres que podem ser usados nos arquivos de origem. Esse conjunto inclui o caractere de espaço, guia horizontal, barra vertical, feed de formulário e caracteres de controle de nova linha, e o conjunto de caracteres de gráficos:  
  
 `a b c d e f g h i j k l m n o p q r s t u v w x y z`  
  
 `A B C D E F G H I J K L M N O P Q R S T U V W X Y Z`  
  
 `0 1 2 3 4 5 6 7 8 9`  
  
 `_ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " '`  
  
 **Seção específica da Microsoft**  
  
 O Visual C++ inclui o `$` caractere como um membro do conjunto de caracteres de origem básico. Visual C++ também permite que um conjunto adicional de caracteres a ser usado nos arquivos de origem, com base na codificação do arquivo. Por padrão, o Visual Studio armazena arquivos de origem usando a página de código padrão. Quando os arquivos de origem são salvos usando uma página de código específicas de localidade ou uma página de código Unicode, Visual C++ permite que você use os caracteres da página de código em seu código-fonte, exceto para os códigos de controle não explicitamente permitidos no caractere fonte básica definido. Por exemplo, você pode colocar caracteres japoneses em comentários, identificadores ou literais de cadeia de caracteres se você salvar o arquivo usando uma página de código japonês. Visual C++ não permite que as sequências de caracteres que não podem ser convertidas em caracteres multibyte válidos ou pontos de código Unicode. Dependendo das opções de compilador permitidos todos os caracteres podem aparecer em identificadores. Para obter mais informações, consulte [Identificadores](../cpp/identifiers-cpp.md).  
  
 **Fim da seção específica da Microsoft**  
  
### <a name="universal-character-names"></a>Nomes de caractere universais  
 Como programas C++ podem usar muitos mais caracteres do que aquelas especificadas no conjunto de caracteres de origem básico, você pode especificar esses caracteres de uma maneira portátil usando *nomes de caractere universal*. Um nome de caractere universal consiste em uma sequência de caracteres que representam um ponto de código Unicode.  Eles têm duas formas. Use `\UNNNNNNNN` para representar um ponto de código Unicode do formulário U + NNNNNNNN, onde NNNNNNNN é o número de ponto de código hexadecimal de oito dígitos. Use quatro dígitos `\uNNNN` representar um ponto de código Unicode do formulário U + 0000NNNN.  
  
 Nomes de caractere universal podem ser usados em identificadores em literais de cadeia de caracteres e caracteres. Um nome de caractere universal não pode ser usado para representar um ponto de código substituto no intervalo 0xD800-0xDFFF. Em vez disso, use o ponto de código desejadas; o compilador gera automaticamente qualquer substitutos necessários. Restrições adicionais se aplicam aos nomes de caractere universal que podem ser usados em identificadores. Para obter mais informações, consulte [identificadores](../cpp/identifiers-cpp.md) e [cadeia de caracteres e literais de caracteres](../cpp/string-and-character-literals-cpp.md).  
  
 **Seção específica da Microsoft**  
  
 O compilador do Visual C++ trata um caractere em formato de nome de caractere universal e formulário literal alternadamente. Por exemplo, você pode declarar um identificador com formato de nome de caractere universal e usá-lo no formulário literal:  
  
```cpp  
auto \u30AD = 42; // \u30AD is 'キ'  
if (キ == 42) return true; // \u30AD and キ are the same to the compiler  
  
```  
  
 O formato de caracteres estendidos na área de transferência do Windows é específico para as configurações de localidade do aplicativo. Recortando e colando esses caracteres em seu código de outro aplicativo podem apresentar codificações de caractere inesperado. Isso pode resultar em erros de análise sem causa visível no seu código. É recomendável que você defina sua origem codificação do arquivo para uma página de código Unicode antes de colar caracteres estendidos. Também recomendamos que você use um IME ou o aplicativo do mapa de caracteres para gerar caracteres estendidos.  
  
 **Fim da seção específica da Microsoft**  
  
### <a name="basic-execution-character-set"></a>Conjunto de caracteres de execução básico  
 O *conjunto de caracteres de execução básico* e *conjunto de caracteres amplo de execução básico* consistem em todos os caracteres no conjunto de caracteres de origem básico e os caracteres de controle que representam o alerta BACKSPACE, retorno de carro e o caractere nulo.   O *conjunto de caracteres de execução* e *conjunto de caracteres largos execução* são subconjuntos dos conjuntos básicos. Eles incluem os caracteres de origem implementação definida fora do conjunto de caracteres de origem básico. O conjunto de caracteres de execução tem uma representação específica de localidade.