---
title: Ferramentas de vinculador LNK1309 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1309
dev_langs:
- C++
helpviewer_keywords:
- LNK1309
ms.assetid: 10146071-883f-4849-97d1-c7468f90efbb
caps.latest.revision: 7
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6d4a8648bf13aa60c234e09cc6d937cfa8435419
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1309"></a>Erro das Ferramentas de Vinculador LNK1309
módulo type1 detectado; inválida com a opção /CLRIMAGETYPE:type2  
  
 Um tipo de imagem CLR foi solicitado com **/CLRIMAGETYPE** , mas o vinculador não pôde produzir uma imagem desse tipo porque um ou mais módulos eram incompatíveis com esse tipo.  
  
 Por exemplo, você verá LNK1309 se você especificar **/CLRIMAGETYPE:safe** e passar um módulo compilado com **/clr: puro**.  
  
 Você também verá LNK1309 se você tentar criar um aplicativo parcialmente confiável de pura CLR usando. lib ptrustu [d]. Para obter informações sobre como criar um aplicativo parcialmente confiável, consulte [como: criar um aplicativo parcialmente confiável pela remoção de dependência na DLL de biblioteca CRT](../../dotnet/create-a-partially-trusted-application.md).  
  
 Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) e [/CLRIMAGETYPE (especificar tipo de imagem CLR)](../../build/reference/clrimagetype-specify-type-of-clr-image.md).
