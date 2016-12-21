---
title: "ML and ML64 Command-Line Reference | Microsoft Docs"
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
  - "ML"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "/W* MASM compiler option"
  - "/c MASM compiler option"
  - "/EP MASM compiler option"
  - "/Fe MASM compiler option"
  - "/Zp MASM compiler option"
  - "/AT MASM compiler option"
  - "/Zm MASM compiler option"
  - "/Sf MASM compiler option"
  - "/Sp MASM compiler option"
  - "/w MASM compiler option"
  - "/Fl MASM compiler option"
  - "/coff MASM compiler option"
  - "/St MASM compiler option"
  - "/Cx MASM compiler option"
  - "/Sl MASM compiler option"
  - "/Cu MASM compiler option"
  - "MASM (Microsoft Macro Assembler), ML command-line reference"
  - "/FPi MASM compiler option"
  - "/Zf MASM compiler option"
  - "ML environment variable"
  - "/Fr MASM compiler option"
  - "/help MASM compiler option"
  - "/Sa MASM compiler option"
  - "/Zd MASM compiler option"
  - "/I MASM compiler option"
  - "/? MASM compiler option"
  - "/Bl MASM compiler option"
  - "/Fm MASM compiler option"
  - "/Fo MASM compiler option"
  - "command-line reference [ML]"
  - "/Sn MASM compiler option"
  - "/Gd MASM compiler option"
  - "/D* MASM compiler option"
  - "environment variables, ML"
  - "/Gc MASM compiler option"
  - "/F* MASM compiler option"
  - "/Sc MASM compiler option"
  - "/H MASM compiler option"
  - "/Zs MASM compiler option"
  - "/omf MASM compiler option"
  - "/Sg MASM compiler option"
  - "/Cp MASM compiler option"
  - "/Zi MASM compiler option"
  - "/nologo MASM compiler option"
  - "/Sx MASM compiler option"
  - "/WX MASM compiler option"
  - "/Ss MASM compiler option"
  - "command line, reference [ML]"
  - "/Ta MASM compiler option"
ms.assetid: 712623c6-f77e-47ea-a945-089e57c50b40
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML and ML64 Command-Line Reference
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Monta e vincula um ou mais arquivos de origem de linguagem assembler.  As opções de linha de comando diferenciam maiúsculas de minúsculas.  
  
 Para obter mais informações sobre ml64.exe, consulte [MASM for x64 \(ml64.exe\)](../../assembler/masm/masm-for-x64-ml64-exe.md).  
  
## Sintaxe  
  
```  
ML [[options]] filename [[ [[options]]  filename]]  
ML64 [[options]] filename [[ [[options]]  filename]]  
...  
[[/link linkoptions]]  
```  
  
#### Parâmetros  
 `options`  
 As opções listadas na tabela a seguir.  
  
|Opção|Ação|  
|-----------|----------|  
|**\/AT**|Ativa o suporte de modelo de memória pequenos.  Permite que mensagens de erro para construções de código que violam os requisitos para arquivos de formato. com.  Observe que isso não é equivalente a  [.MODELO](../../assembler/masm/dot-model.md)**TINY** diretiva.<br /><br /> Não está disponível em ml64.exe.|  
|**\/Bl** `filename`|Seleciona um vinculador alternativo.|  
|**\/c**|Monta apenas.  Não vincula.|  
|**\/coff**|Gera o tipo de formato COFF comum do objeto arquivo de módulo do objeto.  Geralmente são necessárias para o desenvolvimento de linguagem assembly do Win32.<br /><br /> Não está disponível em ml64.exe.|  
|**\/Cp**|Preserva a diferenciação de todos os identificadores de usuário.|  
|**\/Cu**|Mapeia todos os identificadores para letras maiúsculas \(padrão\).<br /><br /> Não está disponível em ml64.exe.|  
|**\/Cx**|Preserva a diferenciação em símbolos públicos e externo.|  
|**\/D** `symbol`\[\[\=`value`\]\]|Define uma macro de texto com o nome fornecido.  Se `value` está faltando, está em branco.  Vários tokens separados por espaços devem ser colocados entre aspas.|  
|**\/EP**|Gera uma listagem de origem pré\-processado \(enviada para STDOUT\).  Consulte **\/Sf**.|  
|**\/ERRORREPORT** \[ **NONE** &#124; **PROMPT** &#124; **QUEUE** &#124; **SEND** \]|Se ml.exe ou ml64.exe falhar em tempo de execução, você pode usar **\/ERRORREPORT** para enviar informações à Microsoft sobre esses erros internos.<br /><br /> Para obter mais informações sobre o **\/ERRORREPORT**, consulte [\/errorReport \(erros de compilador internos do relatório\)](../Topic/-errorReport%20\(Report%20Internal%20Compiler%20Errors\).md).|  
|**\/F** `hexnum`|Tamanho da pilha de conjuntos de `hexnum` bytes \(isso é o mesmo que **\/link\/STACK**:`number`\).  O valor deve ser expresso em notação hexadecimal.  Deve haver um espaço entre **\/F** e `hexnum`.|  
|**\/Fe** `filename`|Nomeia o arquivo executável.|  
|**\/Fl**\[\[`filename`\]\]|Gera uma listagem de código montado.  Consulte **\/Sf**.|  
|**\/Fm**\[\[`filename`\]\]|Cria um arquivo de mapa do vinculador.|  
|**\/Fo** `filename`|Nomeia um arquivo de objeto.  Consulte a seção de comentários para obter mais informações.|  
|**\/FPi**|Gera o emulador correção\-ups para aritmética de ponto flutuante \(somente no idioma misto\).<br /><br /> Não está disponível em ml64.exe.|  
|**\/Fr**\[\[`filename`\]\]|Gera um arquivo de .sbr do navegador de código\-fonte.|  
|**\/FR**\[\[`filename`\]\]|Gera um formulário estendido de um arquivo de .sbr do navegador de código\-fonte.|  
|**\/Gc**|Especifica o uso da função de estilo de Pascal ou FORTRAN chamando e convenções de nomenclatura.  Same as **OPTION LANGUAGE:PASCAL**.<br /><br /> Não está disponível em ml64.exe.|  
|**\/Gd**|Especifica o uso da função do estilo c chamando e convenções de nomenclatura.  Same as **OPTION LANGUAGE:C**.<br /><br /> Não está disponível em ml64.exe.|  
|**\/GZ**|Especifica o uso da função \_\_stdcall chamando e convenções de nomenclatura.  Same as **OPTION LANGUAGE:STCALL**.<br /><br /> Não está disponível em ml64.exe.|  
|**\/H** `number`|Restringe a nomes externos para caracteres de números significativos.  O padrão é de 31 caracteres.<br /><br /> Não está disponível em ml64.exe.|  
|**\/help**|Chama da ajuda rápida para obter ajuda sobre ML.|  
|**\/I** `pathname`|Caminho de conjuntos para arquivo de inclusão.  Um máximo de 10 **\/I** opções é permitido.|  
|**\/nologo**|Suprime as mensagens para o assembly com êxito.|  
|**\/omf**|Gera o tipo de formato \(OMF\) de arquivo de módulo de objeto do módulo do objeto.  **\/omf**implies **\/c**; ML.exe não oferece suporte à vinculação de objetos OMF.<br /><br /> Não está disponível em ml64.exe.|  
|**\/Sa**|Ativa a listagem de todas as informações disponíveis.|  
|**\/safeseh**|Marca o objeto como contendo sem manipuladores de exceção ou que contém manipuladores de exceção são declarados com  [.\/SafeSEH](../Topic/.SAFESEH.md).<br /><br /> Não está disponível em ml64.exe.|  
|**\/Sf**|Adiciona o arquivo de listagem para listagem de primeiro passo.|  
|**\/Sl** `width`|Define a largura de linha da listagem em caracteres por linha de origem.  O intervalo é de 60 a 255 ou 0.  O padrão é 0.  Mesmo que  [página](../../assembler/masm/page.md) largura.|  
|**\/Sn**|Desativa a tabela de símbolos ao produzir uma listagem.|  
|**\/Sp** `length`|Define o comprimento da página de listagem em linhas por página de origem.  O intervalo é de 10 a 255 ou 0.  O padrão é 0.  Mesmo que  [página](../../assembler/masm/page.md) comprimento.|  
|**\/Ss** `text`|Especifica o texto para a listagem de código\-fonte.  Mesmo que  [SUBTÍTULO](../../assembler/masm/subtitle.md) texto.|  
|**\/St** `text`|Especifica o título para a listagem de código\-fonte.  Mesmo que  [título](../../assembler/masm/title.md) texto.|  
|**\/Sx**|Ativa condicionais falsos na listagem.|  
|**\/Ta** `filename`|Monta o arquivo de origem cujo nome não termina com a extensão .asm.|  
|**\/w**|Same as **\/W0\/WX**.|  
|**\/W** `level`|Define o nível de aviso, onde `level` \= 0, 1, 2 ou 3.|  
|**\/WX**|Retorna um código de erro se avisos são gerados.|  
|**\/X**|Ignore o caminho do ambiente de INCLUSÃO.|  
|**\/Zd**|Gera informações de número de linha no arquivo de objeto.|  
|**\/Zf**|Faz com que todos os símbolos públicos.|  
|**\/Zi**|Gera informações do CodeView no arquivo de objeto.|  
|**\/Zm**|Permite que**M510** opção para compatibilidade máxima com MASM 5.1.<br /><br /> Não está disponível em ml64.exe.|  
|**\/Zp**\[\[`alignment`\]\]|Estruturas de pacotes no limite de byte especificado.  O `alignment` pode ser 1, 2 ou 4.|  
|**\/Zs**|Executa uma verificação de sintaxe somente.|  
|**\/?**|Exibe um resumo da sintaxe de linha de comando do ML.|  
  
 `filename`  
 O nome do arquivo.  
  
 `linkoptions`  
 As opções de link.  Consulte [Opções de vinculador](../../build/reference/linker-options.md) para obter mais informações.  
  
## Comentários  
 Algumas opções de linha de comando para ML e ML64 são sensíveis à colocação.  Por exemplo, porque ML e ML64 podem aceitar vários **\/c** opções, qualquer correspondente **\/Fo** opções devem ser especificadas antes **\/c**.  O exemplo de linha de comando a seguir ilustra uma especificação de arquivo de objeto para cada especificação de arquivo do assembly:  
  
 **ml.exe \/Fo a1.obj \/c a.asm \/Fo b1.obj \/c b.asm**  
  
## Environment Variables  
  
|Variável|Descrição|  
|--------------|---------------|  
|INCLUIR|Especifica o caminho de pesquisa para arquivos de inclusão.|  
|ML|Especifica as opções de linha de comando padrão.|  
|TMP|Especifica o caminho para os arquivos temporários.|  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)   
 [Microsoft Macro Assembler Reference](../../assembler/masm/microsoft-macro-assembler-reference.md)