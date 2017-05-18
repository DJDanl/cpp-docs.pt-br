---
title: Argumentos para main | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 39824fef-05ad-461d-ae82-49447dda8060
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 338aa70c280b7638369443b66714c82b7a149d51
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="arguments-to-main"></a>Argumentos para main
**ANSI 2.1.2.2.1** A semântica dos argumentos para main  
  
 No Microsoft C, a função chamada na inicialização do programa é chamada **main**. Não há nenhum protótipo declarado para **main** e ele pode ser definido com zero, dois ou três parâmetros:  
  
```  
int main( void )  
int main( int argc, char *argv[] )  
int main( int argc, char *argv[], char *envp[] )  
```  
  
 A terceira linha acima, em que **main** aceita três parâmetros, é uma extensão da Microsoft para o padrão ANSI C. O terceiro parâmetro, **envp**, é uma matriz dos ponteiros para variáveis de ambiente. A matriz **envp** é terminada por um ponteiro nulo. Consulte [A função main e a execução do programa](../c-language/main-function-and-program-execution.md) para obter mais informações sobre **main** e **envp**.  
  
 A variável **argc** nunca contém um valor negativo.  
  
 A matriz de cadeias de caracteres termina com **argv[argc]**, que contém um ponteiro nulo.  
  
 Todos os elementos da matriz **argv** são ponteiros para cadeias de caracteres.  
  
 Um programa invocado sem argumentos de linha de comando receberá um valor de um para **argc**, já que o nome do arquivo executável é colocado em **argv[0]**. (Em versões do MS-DOS anteriores a 3.0, o nome do arquivo executável não está disponível. A letra “C” é colocada em **argv[0]**.) As cadeias de caracteres apontadas por **argv[1]** a **argv[argc – 1]** representam parâmetros do programa.  
  
 Os parâmetros **argc** e **argv** são modificáveis e retêm seus últimos valores armazenados entre a inicialização do programa e o término do programa.  
  
## <a name="see-also"></a>Consulte também  
 [Ambiente](../c-language/environment.md)
