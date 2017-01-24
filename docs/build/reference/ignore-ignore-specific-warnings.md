---
title: "/IGNORE (Ignorar os Avisos Espec&#237;ficos) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/ignore"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /IGNORE"
ms.assetid: 37e77387-8838-4697-898f-d376ac641124
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /IGNORE (Ignorar os Avisos Espec&#237;ficos)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/IGNORE:warning[,warning]  
```  
  
## Parâmetros  
 `warning`  
 O número de avisos do vinculador para suprimir, no intervalo de 4000 a 4999.  
  
## Comentários  
 Por padrão, o LINK relata todos os avisos.  Especifique **\/IGNORE:**`warning` para informar ao vinculador para suprimir um número específico de avisos.  Para ignorar diversos avisos, separe os números de aviso com vírgulas.  
  
 O vinculador não permite que alguns avisos sejam ignorados.  Esta tabela lista os avisos não serão suprimidos por **\/IGNORE**:  
  
|Aviso do Vinculador||  
|-------------------------|-|  
|LNK4017|A instrução `keyword` não é suportada para a plataforma de destino; ignorada|  
|[LNK4044](../../error-messages/tool-errors/linker-tools-warning-lnk4044.md)|opção não reconhecida "`option`"; ignorada|  
|LNK4062|'`option`" não é compatível com a máquina de destino "`architecture`"; opção ignorada|  
|[LNK4075](../../error-messages/tool-errors/linker-tools-warning-lnk4075.md)|Ignorando "`option1`" devido a especificação "`option2`"|  
|[LNK4086](../../error-messages/tool-errors/linker-tools-warning-lnk4086.md)|O ponto de entrada "`function`" não é \_\_stdcall com "`number`" bytes de argumentos; a imagem pode não ser executada|  
|LNK4088|Imagem sendo gerada devido a opção \/FORCE; a imagem pode não ser executada|  
|[LNK4105](../Topic/Linker%20Tools%20Warning%20LNK4105.md)|nenhum argumento especificado com a opção "`option`"; ignorando o comutador|  
|LNK4203|Erro ao ler o banco de dados do programa "`filename`"; vinculando objeto como se não houvesse informações de depuração|  
|[LNK4204](../../error-messages/tool-errors/linker-tools-warning-lnk4204.md)|'`filename`" está faltando informações de depuração para o módulo de referência; vinculando o objeto como se não houvesse informações de depuração|  
|[LNK4205](../Topic/Linker%20Tools%20Warning%20LNK4205.md)|'`filename`" está faltando informações de depuração para o módulo de referência; vinculando o objeto como se não houvesse informações de depuração|  
|[LNK4206](../../error-messages/tool-errors/linker-tools-warning-lnk4206.md)|As informações sobre o tipo pré\-compilado não foram encontradas; "`filename`" não vinculado ou substituído; vinculando objeto como se não houvesse informações de depuração|  
|LNK4207|'`filename`" compilou \/Yc \/Yu \/Z7; não é possível criar PDB; recompilar com \/Zi; vinculando objeto como se não houvesse informações de depuração|  
|LNK4208|Formato de PDB incompatível no "`filename`"; excluir e recompilar; vinculando objeto como se não houvesse informações de depuração|  
|LNK4209|depurando informações corrompidas; recompilar módulo; vinculando objeto como se não houvesse informações de depuração|  
|[LNK4224](../../error-messages/tool-errors/linker-tools-warning-lnk4224.md)|`option` não é mais suportado; ignorado|  
|LNK4228|'`option`' inválido para um DLL; ignorado|  
|[LNK4229](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md)|Diretiva inválida \/`directive` encontrada; ignorada|  
  
 Em geral, os avisos do vinculador que não podem ser ignorados representam falhas de compilação, erros de linha de comando ou erros de configuração que devem ser corrigidos.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Na pasta **Vinculador**, selecione a página de propriedades **Linha de Comandos**.  
  
3.  Modificar a propriedade **Opções Adicionais**.  
  
### Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.