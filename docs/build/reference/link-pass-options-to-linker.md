---
title: "-link (opções de passagem para o vinculador) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /link
dev_langs: C++
helpviewer_keywords:
- /link compiler option [C++]
- pass options to linker
- link compiler option [C++]
- linker [C++], passing options to
- -link compiler option [C++]
- cl.exe compiler [C++], passing options to linker
ms.assetid: 16902a94-c094-4328-841f-3ac94ca04848
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d6732f5a2b144172939e23af4addb37b7605de11
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="link-pass-options-to-linker"></a>/link (passar opções para o vinculador)
Passa uma ou mais opções de vinculador para o vinculador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/link linkeroptions  
```  
  
## <a name="arguments"></a>Arguments  
 `linkeroptions`  
 A opção de vinculador ou opções a serem passados para o vinculador.  
  
## <a name="remarks"></a>Comentários  
 O **/link** opção e suas opções de vinculador devem aparecer após quaisquer nomes de arquivo e opções de CL. Um espaço é necessário entre **/link** e `linkeroptions`. Para obter mais informações, consulte [definindo opções de vinculador](../../build/reference/setting-linker-options.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique em uma página de propriedade do vinculador.  
  
4.  Modificar uma ou mais propriedades.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Essa opção de compilador não pode ser alterada de forma programática.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)