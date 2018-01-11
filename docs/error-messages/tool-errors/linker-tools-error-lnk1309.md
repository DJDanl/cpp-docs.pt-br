---
title: Ferramentas de vinculador LNK1309 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK1309
dev_langs: C++
helpviewer_keywords: LNK1309
ms.assetid: 10146071-883f-4849-97d1-c7468f90efbb
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 425fb564ae2bd099746fc9b76b496595caa10a0b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1309"></a>Erro das Ferramentas de Vinculador LNK1309
módulo type1 detectado; inválida com a opção /CLRIMAGETYPE:type2  
  
 Um tipo de imagem CLR foi solicitado com **/CLRIMAGETYPE** , mas o vinculador não pôde produzir uma imagem desse tipo porque um ou mais módulos são incompatíveis com o tipo.  
  
 Por exemplo, você verá LNK1309 se você especificar **Safe** e passar um módulo compilado com **/clr: pure**.  
  
 Você também verá LNK1309 se você tentar compilar um aplicativo parcialmente confiável de puro CLR usando. lib de ptrustu [d]. Para obter informações sobre como criar um aplicativo parcialmente confiável, consulte [como: criar um aplicativo parcialmente confiável pela remoção de dependência na DLL da biblioteca CRT](../../dotnet/create-a-partially-trusted-application.md).  
  
 Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) e [/CLRIMAGETYPE (especificar tipo de imagem CLR)](../../build/reference/clrimagetype-specify-type-of-clr-image.md).