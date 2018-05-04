---
title: -IGNORE (ignorar os avisos específicos) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /OVERWRITE
dev_langs:
- C++
helpviewer_keywords:
- /IGNORE linker option
ms.assetid: 37e77387-8838-4697-898f-d376ac641124
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b096fc12f69fbe637a3067646c20f6d520a9250f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="ignore-ignore-specific-warnings"></a>/IGNORE (Ignorar os Avisos Específicos)
```  
/IGNORE:warning[,warning]  
```  
  
## <a name="parameters"></a>Parâmetros  
 `warning`  
 O número de avisos do vinculador para suprimir, no intervalo de 4000 a 4999.  
  
## <a name="remarks"></a>Comentários  
 Por padrão, o LINK relata todos os avisos. Especifique **ignorar:** `warning` para informar o vinculador para suprimir um número específico de aviso. Para ignorar diversos avisos, separe os números de aviso com vírgulas.  
  
 O vinculador não permite que alguns avisos sejam ignorados. Esta tabela lista os avisos que não são suprimidos pela **ignorar**:  
  
|Aviso do Vinculador||  
|--------------------|-|  
|LNK4017|A instrução `keyword` não é suportada para a plataforma de destino; ignorada|  
|[LNK4044](../../error-messages/tool-errors/linker-tools-warning-lnk4044.md)|opção não reconhecida "`option`"; ignorada|  
|LNK4062|'`option`'não é compatível com'`architecture`' da máquina de destino; opção ignorada|  
|[LNK4075](../../error-messages/tool-errors/linker-tools-warning-lnk4075.md)|Ignorando "`option1`" devido a especificação "`option2`"|  
|[LNK4086](../../error-messages/tool-errors/linker-tools-warning-lnk4086.md)|O ponto de entrada "`function`" não é __stdcall com "`number`" bytes de argumentos; a imagem pode não ser executada|  
|LNK4088|Imagem sendo gerada devido a opção /FORCE; a imagem pode não ser executada|  
|[LNK4105](../../error-messages/tool-errors/linker-tools-warning-lnk4105.md)|nenhum argumento especificado com a opção "`option`"; ignorando o comutador|  
|LNK4203|Erro ao ler o banco de dados do programa "`filename`"; vinculando objeto como se não houvesse informações de depuração|  
|[LNK4204](../../error-messages/tool-errors/linker-tools-warning-lnk4204.md)|'`filename`' está faltando a depuração de informações de referência de módulo; vinculando objeto quando sem informação de depuração|  
|[LNK4205](../../error-messages/tool-errors/linker-tools-warning-lnk4205.md)|'`filename`' está faltando informação de depuração para a referência de módulo; vinculando objeto quando sem informação de depuração|  
|[LNK4206](../../error-messages/tool-errors/linker-tools-warning-lnk4206.md)|As informações sobre o tipo pré-compilado não foram encontradas; "`filename`" não vinculado ou substituído; vinculando objeto como se não houvesse informações de depuração|  
|LNK4207|'`filename`' compilou /Yc /Yu /Z7; não é possível criar PDB; recompile com /Zi; vinculação de objeto quando sem informação de depuração|  
|LNK4208|Formato de PDB incompatível no "`filename`"; excluir e recompilar; vinculando objeto como se não houvesse informações de depuração|  
|LNK4209|depurando informações corrompidas; recompilar módulo; vinculando objeto como se não houvesse informações de depuração|  
|[LNK4224](../../error-messages/tool-errors/linker-tools-warning-lnk4224.md)|`option` não é mais suportado; ignorado|  
|LNK4228|'`option`' inválido para uma DLL; ignorado|  
|[LNK4229](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md)|Diretiva inválida /`directive` encontrada; ignorada|  
  
 Em geral, os avisos do vinculador que não podem ser ignorados representam falhas de compilação, erros de linha de comando ou erros de configuração que devem ser corrigidos.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No **vinculador** pasta, selecione o **linha de comando** página de propriedades.  
  
3.  Modificar o **opções adicionais** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.