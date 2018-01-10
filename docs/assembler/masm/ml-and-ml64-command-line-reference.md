---
title: "Referência de linha de comando ML e ML64 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: ML
dev_langs: C++
helpviewer_keywords:
- /W* MASM compiler option
- /c MASM compiler option
- /EP MASM compiler option
- /Fe MASM compiler option
- /Zp MASM compiler option
- /AT MASM compiler option
- /Zm MASM compiler option
- /Sf MASM compiler option
- /Sp MASM compiler option
- /w MASM compiler option
- /Fl MASM compiler option
- /coff MASM compiler option
- /St MASM compiler option
- /Cx MASM compiler option
- /Sl MASM compiler option
- /Cu MASM compiler option
- MASM (Microsoft Macro Assembler), ML command-line reference
- /FPi MASM compiler option
- /Zf MASM compiler option
- ML environment variable
- /Fr MASM compiler option
- /help MASM compiler option
- /Sa MASM compiler option
- /Zd MASM compiler option
- /I MASM compiler option
- /? MASM compiler option
- /Bl MASM compiler option
- /Fm MASM compiler option
- /Fo MASM compiler option
- command-line reference [ML]
- /Sn MASM compiler option
- /Gd MASM compiler option
- /D* MASM compiler option
- environment variables, ML
- /Gc MASM compiler option
- /F* MASM compiler option
- /Sc MASM compiler option
- /H MASM compiler option
- /Zs MASM compiler option
- /omf MASM compiler option
- /Sg MASM compiler option
- /Cp MASM compiler option
- /Zi MASM compiler option
- /nologo MASM compiler option
- /Sx MASM compiler option
- /WX MASM compiler option
- /Ss MASM compiler option
- command line, reference [ML]
- /Ta MASM compiler option
ms.assetid: 712623c6-f77e-47ea-a945-089e57c50b40
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4a7a2a5baadab38283b621cb2f6ae99b36fe0a50
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ml-and-ml64-command-line-reference"></a>Referência de linha de comando ML e ML64
Monta e vincula um ou mais arquivos de origem de linguagem de assembly. As opções de linha de comando diferenciam maiusculas de minúsculas.  
  
 Para obter mais informações sobre ml64.exe, consulte [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ML [[options]] filename [[ [[options]]  filename]]  
ML64 [[options]] filename [[ [[options]]  filename]]  
...  
[[/link linkoptions]]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `options`  
 As opções listadas na tabela a seguir.  
  
|Opção|Ação|  
|------------|------------|  
|**/AT**|Habilita o suporte do modelo de memória pequenos. Permite que mensagens de erro para construções de código que violam os requisitos para arquivos de formato. com. Observe que isso não é equivalente a [. MODELO](../../assembler/masm/dot-model.md) **minúscula** diretiva.<br /><br /> Não disponível em ml64.exe.|  
|**/Bl**`filename`|Seleciona um vinculador alternativo.|  
|**/c**|Monta somente. Não vincular.|  
|**/COFF**|Gera o tipo de formato COFF comum do objeto arquivo de módulo de objeto. Geralmente são necessárias para desenvolvimento de linguagem de assembly do Win32.<br /><br /> Não disponível em ml64.exe.|  
|**/CP**|Preserva o caso de todos os identificadores de usuário.|  
|**/Cu**|Mapeia todos os identificadores para letras maiusculas (padrão).<br /><br /> Não disponível em ml64.exe.|  
|**/CX**|Preserva o caso de símbolos públicos e externo.|  
|**/D** `symbol`[[=`value`]]|Define uma macro de texto com o nome fornecido. Se `value` estiver ausente, ele estará em branco. Vários tokens separados por espaços devem ser colocados entre aspas.|  
|**/EP**|Gera uma lista de origem pré-processados (enviada para STDOUT). Consulte **/Sf**.|  
|**/ERRORREPORT** [ **NONE** &#124; **PROMPT** &#124; **FILA** &#124; **ENVIAR** ]|Se ml.exe ou ml64.exe falhar em tempo de execução, você pode usar **/ERRORREPORT** para enviar à Microsoft informações sobre esses erros internos.<br /><br /> Para obter mais informações sobre **/ERRORREPORT**, consulte [/errorReport (relatório de erros do compilador interno)](../../build/reference/errorreport-report-internal-compiler-errors.md).|  
|**/F**`hexnum`|Tamanho de pilha de conjuntos de `hexnum` bytes (Isso é o mesmo que **/link/pilha**:`number`). O valor deve ser expressa em notação hexadecimal. Deve haver um espaço entre **/F** e `hexnum`.|  
|**/FE**`filename`|Nomeia o arquivo executável.|  
|**/FL**[[`filename`]]|Gera uma listagem de código montado. Consulte **/Sf**.|  
|**/FM**[[`filename`]]|Cria um arquivo de mapa do vinculador.|  
|**/FO**`filename`|Nomes de um arquivo de objeto. Consulte a seção comentários para obter mais informações.|  
|**/Fpi**|Gera as correções do emulador para aritmética de ponto flutuante (somente no idioma misto).<br /><br /> Não disponível em ml64.exe.|  
|**/FR**[[`filename`]]|Gera um arquivo. SBR do navegador de fonte.|  
|**/FR**[[`filename`]]|Gera uma forma estendida de um navegador. SBR do arquivo de origem.|  
|**/GC**|Especifica o uso da função de estilo FORTRAN ou Pascal chamando e convenções de nomenclatura. Mesmo que **opção LANGUAGE: PASCAL**.<br /><br /> Não disponível em ml64.exe.|  
|**/Gd**|Especifica o uso da função de estilo C chamando e convenções de nomenclatura. Mesmo que **opção LANGUAGE: C**.<br /><br /> Não disponível em ml64.exe.|  
|**/GZ**|Especifica o uso da função de stdcall chamando e convenções de nomenclatura.  Mesmo que **opção LANGUAGE: STCALL**.<br /><br /> Não disponível em ml64.exe.|  
|**/H**`number`|Restringe nomes externos para o número de caracteres significativo. O padrão é 31 caracteres.<br /><br /> Não disponível em ml64.exe.|  
|**/help**|Chama da ajuda rápida para obter ajuda sobre ML.|  
|**/I**`pathname`|Caminho de conjuntos de arquivo de inclusão. Um máximo de 10 **/i** opções é permitido.|  
|**/nologo**|Suprime mensagens para o assembly com êxito.|  
|**/OMF**|Gera o tipo de formato (OMF) de arquivo de módulo de objeto de módulo de objeto.  **/OMF** implica **/c**; ML.exe não oferece suporte à vinculação objetos OMF.<br /><br /> Não disponível em ml64.exe.|  
|**/SA**|Ativa a lista de todas as informações disponíveis.|  
|**/SafeSEH**|Marca o objeto como contendo sem manipuladores de exceção ou que contém os manipuladores de exceção que são declarados com [. SAFESEH](../../assembler/masm/dot-safeseh.md).<br /><br /> Não disponível em ml64.exe.|  
|**/SF**|Adiciona um arquivo de listagem a listagem do primeiro passo.|  
|**/SL**`width`|Define a largura da linha de origem na caracteres por linha. Intervalo é de 60 a 255 ou 0. O padrão é 0. Mesmo que [página](../../assembler/masm/page.md) largura.|  
|**/Sn**|Desativa a tabela de símbolos durante a produção de uma lista.|  
|**/SP**`length`|Define o tamanho de página de origem listando em linhas por página. Intervalo é de 10 a 255 ou 0. O padrão é 0. Mesmo que [página](../../assembler/masm/page.md) comprimento.|  
|**/SS**`text`|Especifica o texto para a lista de origem. Mesmo que [SUBTÍTULO](../../assembler/masm/subtitle.md) texto.|  
|**/ST**`text`|Especifica o título para a lista de origem. Mesmo que [título](../../assembler/masm/title.md) texto.|  
|**/SX**|Ativa condicionais falsas na listagem.|  
|**/TA**`filename`|Monta o arquivo de origem cujo nome não pode terminar com a extensão. ASM.|  
|**/w**|Mesmo que **W0/WX**.|  
|**/W**`level`|Define o nível de aviso, onde `level` = 0, 1, 2 ou 3.|  
|**/WX**|Retorna um código de erro se o aviso é gerado.|  
|**/X**|Ignore caminho de ambiente INCLUDE.|  
|**/Zd**|Gera informações de número de linha no arquivo de objeto.|  
|**/ZF**|Faz com que todos os símbolos públicos.|  
|**/Zi**|Gera informações de CodeView no arquivo de objeto.|  
|**/ZM**|Permite**M510** opção de máximo de compatibilidade com MASM 5.1.<br /><br /> Não disponível em ml64.exe.|  
|**/ZP**[[`alignment`]]|Empacota estruturas em limites de bytes especificado. O `alignment` pode ser 1, 2 ou 4.|  
|**/ZS**|Executa uma verificação de sintaxe apenas.|  
|**/?**|Exibe um resumo da sintaxe de linha de comando ML.|  
  
 `filename`  
 O nome do arquivo.  
  
 `linkoptions`  
 As opções de link.  Consulte [opções do vinculador](../../build/reference/linker-options.md) para obter mais informações.  
  
## <a name="remarks"></a>Comentários  
 Algumas opções de linha de comando ML e ML64 diferenciam do posicionamento. Por exemplo, porque ML e ML64 podem aceitar várias **/c** opções, qualquer correspondente **/Fo** opções devem ser especificadas antes **/c**. O exemplo de linha de comando a seguir ilustra uma especificação de arquivo de objeto para cada especificação de arquivo de assembly:  
  
 **/Fo ml.exe a1.obj /c a.asm /Fo b1.obj /c b.asm**  
  
## <a name="environment-variables"></a>Variáveis de ambiente  
  
|Variável|Descrição|  
|--------------|-----------------|  
|INCLUDE|Especifica o caminho de pesquisa para incluir arquivos.|  
|ML|Especifica as opções de linha de comando padrão.|  
|TMP|Especifica o caminho para arquivos temporários.|  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro ML](../../assembler/masm/ml-error-messages.md)   
 [Referência do Microsoft Macro Assembler](../../assembler/masm/microsoft-macro-assembler-reference.md)