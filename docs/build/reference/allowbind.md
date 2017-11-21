---
title: -ALLOWBIND | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /allowbind
dev_langs: C++
helpviewer_keywords:
- ALLOWBIND editbin option
- /ALLOWBIND editbin option
- -ALLOWBIND editbin option
ms.assetid: eaadbb8c-4339-4281-9a75-3a1ce2352ff8
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: e1a039a6f62a3cf2dd296677f81f672ab462f7b9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="allowbind"></a>/ALLOWBIND
Especifica se uma DLL pode ser associada.  
  
```  
  
/ALLOWBIND[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 O **/ALLOWBIND** opção define um bit no cabeçalho de uma DLL que indica para Bind.exe que a imagem pode ser associado. Associação pode permitir que uma imagem a ser carregado mais rapidamente quando o carregador não tem rebase e executar a correção de endereço para cada DLL referenciado. Talvez não seja um DLL ser associada caso ele tenha sido assinado digitalmente — associação invalida a assinatura. Associação não tem nenhum efeito se aleatória de layout de espaço de endereço (ASLR) está habilitada para a imagem usando **/DYNAMICBASE** em versões do Windows que oferecem suporte a ASLR.  
  
 Use **/allowbind: no** para impedir que a DLL de associação Bind.exe.  
  
 Para obter mais informações, consulte o [/ALLOWBIND](../../build/reference/allowbind-prevent-dll-binding.md) opção de vinculador.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de EDITBIN](../../build/reference/editbin-options.md)