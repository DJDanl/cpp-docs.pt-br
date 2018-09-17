---
title: -CLRTHREADATTRIBUTE (definir atributo de Thread CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.CLRThreadAttribute
dev_langs:
- C++
helpviewer_keywords:
- /CLRTHREADATTRIBUTE linker option
- -CLRTHREADATTRIBUTE linker option
ms.assetid: 4907e9ef-5031-446c-aecf-0a0b32fae1e8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bea5b75c9f0691ef74c35ed405d64fc3389c4fcd
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45705790"
---
# <a name="clrthreadattribute-set-clr-thread-attribute"></a>/CLRTHREADATTRIBUTE (definir atributo de thread CLR)

Especifica explicitamente o atributo de thread para o ponto de entrada do seu programa CLR.

## <a name="syntax"></a>Sintaxe

```
/CLRTHREADATTRIBUTE:{STA|MTA|NONE}
```

#### <a name="parameters"></a>Parâmetros

**MTA**<br/>
Aplica o atributo MTAThreadAttribute ao ponto de entrada do seu programa.

**NONE**<br/>
Mesmo que não especificar /CLRTHREADATTRIBUTE.  Permite que o tempo de execução de linguagem comum (CLR) defina o atributo threading padrão.

**STA**<br/>
Aplica o atributo STAThreadAttribute ao ponto de entrada do seu programa.

## <a name="remarks"></a>Comentários

Definindo o atributo de thread só é válida ao criar um .exe, pois isso afeta o ponto de entrada do thread principal.

Se você usar o ponto de entrada padrão (main ou wmain, por exemplo) Especifique o modelo de threading usando /CLRTHREADATTRIBUTE ou colocando o threading de atributo (STAThreadAttribute ou MTAThreadAttribute) na função de entrada padrão.

Se você usar um ponto de entrada não padrão, especifique o modelo de threading usando /CLRTHREADATTRIBUTE ou colocando o threading de atributo na função de entrada não padrão e, em seguida, especifique o ponto de entrada não padrão com [/ENTRY](../../build/reference/entry-entry-point-symbol.md) .

Se o modelo de threading especificado no código-fonte não concordar com o modelo de threading especificado com /CLRTHREADATTRIBUTE, o vinculador ignorará /CLRTHREADATTRIBUTE e aplicar o modelo de threading especificado no código-fonte.

Será necessário para que você possa usar o threading simples, por exemplo, se um objeto COM que usa o threading simples hospedar o seu programa CLR.  Se o CLR usa vários threads de programa, ele não é possível hospedar um objeto COM que usa o threading simples.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o **vinculador** nó.

1. Selecione o **avançado** página de propriedades.

1. Modificar a **atributo de Thread CLR** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.CLRThreadAttribute%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)