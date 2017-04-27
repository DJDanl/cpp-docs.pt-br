---
title: Ferramentas de vinculador LNK1561 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1561
dev_langs:
- C++
helpviewer_keywords:
- LNK1561
ms.assetid: cb0b709b-7c9c-4496-8a4e-9e1e4aefe447
caps.latest.revision: 8
author: corob-msft
ms.author: corob
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
translationtype: Machine Translation
ms.sourcegitcommit: 4bac7b2942f9d72674b8092dc7bf64174dd3c349
ms.openlocfilehash: fbc63a58cd4e276aa2a3f77baeea07d1912eda98
ms.lasthandoff: 04/24/2017

---
# <a name="linker-tools-error-lnk1561"></a>Erro das Ferramentas de Vinculador LNK1561
pontos de entrada devem ser definidos  
  
O vinculador não foi possível encontrar um ponto de entrada. Esse erro pode ter várias causas:  
-   Você pode não ter incluído o arquivo que define o ponto de entrada na lista de arquivos para vincular. Verifique se que o arquivo que contém a função de ponto de entrada está vinculado ao seu aplicativo.  
-   Você definiu o ponto de entrada usando a assinatura de função incorreto; Por exemplo, você pode ter digitado incorretamente usado caso errado para o nome de função ou especificado o tipo de retorno ou tipos de parâmetro incorretamente. Por padrão, o vinculador procura um `main` ou `wmain` função para um aplicativo de console, um `WinMain` ou `wWinMain` função para um aplicativo do Windows, ou `DllMain` para uma DLL que requer inicialização.  
-   Talvez você não tenha especificado o [/DLL](../../build/reference/dll-build-a-dll.md) opção ao criar uma DLL.  
-   Talvez você tenha especificado o nome da função de ponto de entrada incorretamente quando você usou o [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opção de vinculador.  
-   Se você estiver usando o [LIB](../../build/reference/lib-reference.md) ferramenta para criar uma DLL, você pode ter especificado um arquivo. def. Nesse caso, remova o arquivo. def da compilação.    
  
Ao criar um aplicativo, o vinculador procura um *ponto de entrada*, a função de chamada para iniciar seu código. Essa é a função que é chamada depois que o aplicativo é carregado e o tempo de execução é inicializado. Você deve fornecer uma função de ponto de entrada para um aplicativo ou o aplicativo não pode ser executado. Um ponto de entrada é opcional para uma DLL. Por padrão, o vinculador procura uma função de ponto de entrada que tenha um dos vários nomes específicos e assinaturas, como `int main(int, char**)`. Você pode especificar outro nome de função como a entrada, usando a opção de vinculador /ENTRY.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK1561:  
  
```cpp  
// LNK1561.cpp  
// LNK1561 expected  
int i;  
// add a main function to resolve this error  
```
