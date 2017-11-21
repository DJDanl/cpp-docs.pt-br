---
title: Ferramentas de vinculador LNK1561 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK1561
dev_langs: C++
helpviewer_keywords: LNK1561
ms.assetid: cb0b709b-7c9c-4496-8a4e-9e1e4aefe447
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: b3a6ad889969292a65afb7b363412eaf7d7a6430
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-error-lnk1561"></a>Erro das Ferramentas de Vinculador LNK1561
ponto de entrada deve ser definido  
  
O vinculador não localizou um *ponto de entrada*, a função inicial para chamar o executável. Por padrão, o vinculador procura um `main` ou `wmain` função para um aplicativo de console, um `WinMain` ou `wWinMain` função para um aplicativo do Windows, ou `DllMain` para uma DLL que requer inicialização. Você pode especificar outra função usando o [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opção de vinculador.  
  
Esse erro pode ter várias causas:  
-   Você pode não ter incluído o arquivo que define o ponto de entrada na lista de arquivos para vincular. Verifique se que o arquivo que contém a função de ponto de entrada está vinculado ao seu aplicativo.  
-   Você definiu o ponto de entrada usando a assinatura de função incorreto; Por exemplo, você pode ter digitado incorretamente usado caso errado para o nome de função ou especificado o tipo de retorno ou tipos de parâmetro incorretamente.  
-   Talvez você não tenha especificado o [/DLL](../../build/reference/dll-build-a-dll.md) opção ao criar uma DLL.  
-   Talvez você tenha especificado o nome da função de ponto de entrada incorretamente quando você usou o [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opção de vinculador.  
-   Se você estiver usando o [LIB](../../build/reference/lib-reference.md) ferramenta para criar uma DLL, você pode ter especificado um arquivo. def. Nesse caso, remova o arquivo. def da compilação.    
  
Ao criar um aplicativo, o vinculador procura por uma função de ponto de entrada para a chamada para iniciar seu código. Essa é a função que é chamada depois que o aplicativo é carregado e o tempo de execução é inicializado. Você deve fornecer uma função de ponto de entrada para um aplicativo ou o aplicativo não pode ser executado. Um ponto de entrada é opcional para uma DLL. Por padrão, o vinculador procura uma função de ponto de entrada que tenha um dos vários nomes específicos e assinaturas, como `int main(int, char**)`. Você pode especificar outro nome de função como a entrada, usando a opção de vinculador /ENTRY.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK1561:  
  
```cpp  
// LNK1561.cpp  
// LNK1561 expected  
int i;  
// add a main function to resolve this error  
```