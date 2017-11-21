---
title: -CLRTHREADATTRIBUTE (conjunto de atributo do Thread CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: VC.Project.VCLinkerTool.CLRThreadAttribute
dev_langs: C++
helpviewer_keywords:
- /CLRTHREADATTRIBUTE linker option
- -CLRTHREADATTRIBUTE linker option
ms.assetid: 4907e9ef-5031-446c-aecf-0a0b32fae1e8
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: e928d24c6257bc64303d667e66cd1f968e003450
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="clrthreadattribute-set-clr-thread-attribute"></a>/CLRTHREADATTRIBUTE (definir atributo de thread CLR)
Especifica explicitamente o atributo de thread para o ponto de entrada do seu programa CLR.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/CLRTHREADATTRIBUTE:{STA|MTA|NONE}  
```  
  
#### <a name="parameters"></a>Parâmetros  
 MTA  
 Aplica-se o atributo MTAThreadAttribute ao ponto de entrada de seu programa.  
  
 NENHUM  
 Mesmo que não especificar /CLRTHREADATTRIBUTE.  Permite que o tempo de execução de linguagem comum (CLR) definir o atributo threading padrão.  
  
 STA  
 Aplica-se o atributo STAThreadAttribute ao ponto de entrada de seu programa.  
  
## <a name="remarks"></a>Comentários  
 Definindo o atributo de thread só é válida quando estiver criando um .exe, pois isso afeta o ponto de entrada do thread principal.  
  
 Se você usar o ponto de entrada padrão (main ou wmain, por exemplo) Especifique o modelo de threading usando /CLRTHREADATTRIBUTE ou colocando o threading de atributo (STAThreadAttribute ou MTAThreadAttribute) na função de entrada padrão.  
  
 Se você usar um ponto de entrada não padrão, especifique o modelo de threading usando /CLRTHREADATTRIBUTE ou colocando o threading de atributos na função de entrada não padrão e, em seguida, especifique o ponto de entrada não padrão com [/ENTRY](../../build/reference/entry-entry-point-symbol.md) .  
  
 Se o modelo de threading especificado no código-fonte não concorda com o modelo de threading especificado com /CLRTHREADATTRIBUTE, o vinculador ignorará /CLRTHREADATTRIBUTE e aplicar o modelo de threading especificado no código-fonte.  
  
 Será necessário para que você use recursos de thread único, por exemplo, se seu programa CLR hospeda um objeto COM que usa o thread único.  Se o CLR usa vários threads de programa, ele não pode hospedar um objeto COM que usa o thread único.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **avançado** página de propriedades.  
  
5.  Modificar o **atributo de Thread CLR** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.CLRThreadAttribute%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)