---
title: Ferramentas de vinculador LNK1112 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1112
dev_langs:
- C++
helpviewer_keywords:
- LNK1112
ms.assetid: 425793d8-37e6-4072-9b6e-c3d4e9c12562
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a915768f0668a4ce276962f9eafd1f905980e2be
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1112"></a>Erro das Ferramentas de Vinculador LNK1112
módulo máquina tipo 'type1' está em conflito com o tipo de máquina de destino 'type2'  
  
 Os arquivos de objeto especificados como entrada foram compilados para tipos de computador diferente.  
  
 Por exemplo, se você tentar vincular um arquivo de objeto compilado com **/clr** e um arquivo de objeto compilado com **/clr: pure** (tipo CEE de máquina), o vinculador gerará o erro LNK1112.  
  
 Da mesma forma, se você criar um módulo com o [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] compilador e o outro módulo com x86 compilador e tente vinculá-los, o vinculador gerará LNK1112.  
  
 Um motivo possível para esse erro é se você estiver desenvolvendo um aplicativo de 64 bits, mas não tiver instalado um dos compiladores bit 64 do Visual C++. Nesse caso, as configurações de 64 bits não estará disponíveis. Para corrigir esse problema, execute o instalador para o Visual Studio e instale os componentes ausentes do C++.  
  
 Esse erro também poderá ocorrer se você alterar o **configuração de solução ativa** no **do Configuration Manager** e, em seguida, tente compilar o projeto antes de excluir os arquivos de projeto intermediário. Para resolver esse erro, selecione **recompilar solução** do **criar** menu. Você também pode selecionar **limpar solução** do **criar** menu e, em seguida, compilar a solução.  
  
## <a name="see-also"></a>Consulte também  
 [Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)