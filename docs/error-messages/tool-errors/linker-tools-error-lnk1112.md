---
title: Ferramentas de vinculador LNK1112 erro | Documentos do Microsoft
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
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4d404bc6e07a4e709ebab3859a9404795614e39f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1112"></a>Erro das Ferramentas de Vinculador LNK1112
módulo máquina tipo 'type1' está em conflito com o tipo de máquina de destino 'type2'  
  
 Os arquivos de objeto especificados como entrada foram compilados por tipos de computadores diferentes.  
  
 Por exemplo, se você tentar vincular um arquivo de objeto compilado com **/clr** e um arquivo de objeto compilado com **/clr: puro** (tipo CEE de máquina), o vinculador gerará o erro LNK1112.  
  
 Da mesma forma, se você criar um módulo com o [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] compilador e o outro módulo com o x86 compilador e tente vinculá-los, o vinculador irá gerar LNK1112.  
  
 Um motivo possível para esse erro é se você estiver desenvolvendo um aplicativo de 64 bits, mas não tiver instalado um dos compiladores do Visual C++ 64 bits. Nesse caso, as configurações de 64 bits não estará disponíveis. Para corrigir esse problema, execute o instalador do Visual Studio e instalar os componentes ausentes do C++.  
  
 Esse erro também pode ocorrer se você alterar o **configuração de solução ativa** no **do Configuration Manager** e, em seguida, tente compilar o projeto antes de excluir os arquivos intermediários do projeto. Para resolver esse erro, selecione **recompilar solução** do **criar** menu. Você também pode selecionar **limpar solução** do **criar** menu e, em seguida, criar a solução.  
  
## <a name="see-also"></a>Consulte também  
 [Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)
