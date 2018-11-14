---
title: Referência de linha de comando ML e ML64
ms.date: 08/30/2018
f1_keywords:
- ML
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
ms.openlocfilehash: a452bab03e31436ee5dde476117bce8b73c7571f
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51331250"
---
# <a name="ml-and-ml64-command-line-reference"></a>Referência de linha de comando ML e ML64

Monta e vincula um ou mais arquivos de código-fonte da linguagem de assembly. As opções de linha de comando diferenciam maiusculas de minúsculas.

Para obter mais informações sobre ml64.exe, consulte [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

## <a name="syntax"></a>Sintaxe

> ML \[ *opções*] *filename* \[ \[ *opções*] *filename*]
>
> ML64 \[ *opções*] *filename* \[ \[ *opções*] *filename*]... \[/link *linkoptions*]

### <a name="parameters"></a>Parâmetros

*options*<br/>
As opções listadas na tabela a seguir.

|Opção|Ação|
|------------|------------|
|**/AT**|Habilita o suporte de modelo pequeno de memória. Permite que mensagens de erro para construções de código que violam os requisitos para arquivos de formato. com. Observe que isso não é equivalente a [. MODELO](../../assembler/masm/dot-model.md) **TINY** diretiva.<br /><br /> Não disponível em ml64.exe.|
|**/Bl** *nome de arquivo*|Seleciona um vinculador alternativo.|
|**/c**|Monta apenas. Não vincular.|
|**s /COFF.**|Gera o tipo de formato COFF comum do objeto arquivo de módulo de objeto. Em geral, necessários para o desenvolvimento de linguagem de assembly do Win32.<br /><br /> Não disponível em ml64.exe.|
|**/Cp**|Preserva o caso de todos os identificadores de usuário.|
|**/Cu**|Mapeia todos os identificadores de letras maiusculas (padrão).<br /><br /> Não disponível em ml64.exe.|
|**/Cx**|Preserva o caso nos símbolos públicos e extern.|
|**/D** *símbolo*[[=*valor*]]|Define uma macro de texto com o nome fornecido. Se *valor* está ausente, ele estará em branco. Vários tokens separados por espaços devem ser colocados entre aspas.|
|**/EP**|Gera uma listagem de código-fonte pré-processado (enviada para STDOUT). Ver **/Sf**.|
|**/ERRORREPORT** [ **NONE** &#124; **PROMPT** &#124; **QUEUE** &#124; **SEND** ]|Se ml.exe ou ml64.exe falhar em tempo de execução, você pode usar **/ERRORREPORT** para enviar à Microsoft informações sobre esses erros internos.<br /><br /> Para obter mais informações sobre **/ERRORREPORT**, consulte [/errorReport (relatório de erros do compilador interno)](../../build/reference/errorreport-report-internal-compiler-errors.md).|
|**/F** *hexnum*|Conjuntos de tamanho de pilha *hexnum* bytes (Isso é o mesmo que **/link/pilha**:*número*). O valor deve ser expresso em notação hexadecimal. Deve haver um espaço entre **/F** e *hexnum*.|
|**/FE** *nome de arquivo*|Nomeia o arquivo executável.|
|**/FL**[[*filename*]]|Gera uma listagem de código montado. Ver **/Sf**.|
|**/FM**[[*filename*]]|Cria um arquivo de mapa do vinculador.|
|**/FO** *nome de arquivo*|Nomes de um arquivo de objeto. Consulte a seção Observações para obter mais informações.|
|**/FPi**|Gera as correções do emulador para aritmética de ponto flutuante (somente no idioma misto).<br /><br /> Não disponível em ml64.exe.|
|**/FR**[[*filename*]]|Gera um arquivo. SBR do navegador de origem.|
|**/FR**[[*filename*]]|Gera uma forma estendida de um arquivo. SBR do navegador de origem.|
|**/Gc**|Especifica o uso da função de estilo de Pascal ou FORTRAN chamando e convenções de nomenclatura. Mesmo que **opção de LINGUAGEM: PASCAL**.<br /><br /> Não disponível em ml64.exe.|
|**/Gd**|Especifica o uso da função de estilo C chamando e convenções de nomenclatura. Mesmo que **opção de LINGUAGEM: C**.<br /><br /> Não disponível em ml64.exe.|
|**/GZ**|Especifica o uso da função de stdcall chamando e convenções de nomenclatura.  Mesmo que **opção de LINGUAGEM: STCALL**.<br /><br /> Não disponível em ml64.exe.|
|**/H** *número*|Restringe nomes externos ao número de caracteres significativo. O padrão é 31 caracteres.<br /><br /> Não disponível em ml64.exe.|
|**/help**|Chama o QuickHelp para obter ajuda sobre ML.|
|**/I** *pathname*|Caminho de conjuntos para o arquivo de inclusão. Um máximo de 10 **/I** opções é permitida.|
|**/nologo**|Suprime mensagens para o assembly com êxito.|
|**/omf**|Gera o tipo de formato (OMF) de arquivo de módulo de objeto de módulo de objeto.  **/OMF** implica **/c**; ML.exe não oferece suporte à vinculação de objetos OMF.<br /><br /> Não disponível em ml64.exe.|
|**/Sa**|Ativa a lista de todas as informações disponíveis.|
|**/safeseh**|Marca o objeto como não contendo nenhum manipuladores de exceção ou que contém os manipuladores de exceção que são declarados com [. SAFESEH](../../assembler/masm/dot-safeseh.md).<br /><br /> Não disponível em ml64.exe.|
|**/Sf**|Adiciona o arquivo de listagem para listagem do primeiro passo.|
|**/SL** *largura*|Define a largura da linha de listagem em caracteres por linha de origem. Intervalo é 60 a 255 ou 0. O padrão é 0. Mesmo que [página](../../assembler/masm/page.md) largura.|
|**/Sn**|Desativa a tabela de símbolos ao produzir uma lista.|
|**/SP** *comprimento*|Define o tamanho de página de listagem em linhas por página de origem. Intervalo é de 10 a 255 ou 0. O padrão é 0. Mesmo que [página](../../assembler/masm/page.md) comprimento.|
|**/SS** *texto*|Especifica o texto para a listagem de código-fonte. Mesmo que [SUBTÍTULO](../../assembler/masm/subtitle.md) texto.|
|**/ST** *texto*|Especifica o título para a listagem de código-fonte. Mesmo que [título](../../assembler/masm/title.md) texto.|
|**/Sx**|Ativa a falsos condicionais na listagem.|
|**/TA** *nome de arquivo*|Monta o arquivo de origem cujo nome não termina com a extensão. ASM.|
|**/w**|Mesmo que **/W0/WX**.|
|**/W** *nível*|Define o nível de aviso, onde *nível* = 0, 1, 2 ou 3.|
|**/WX**|Retorna um código de erro se os avisos forem gerados.|
|**/X**|Ignore caminho de ambiente INCLUDE.|
|**/Zd**|Gera informações de número de linha no arquivo de objeto.|
|**/Zf**|Faz com que todos os símbolos públicos.|
|**/Zi**|Gera informações de CodeView no arquivo de objeto.|
|**/Zm**|Habilita**M510** opção para máxima compatibilidade com MASM 5.1.<br /><br /> Não disponível em ml64.exe.|
|**/ZP**[[*alinhamento*]]|Empacota estruturas em que o limite de bytes especificada. O *alinhamento* pode ser 1, 2 ou 4.|
|**/Zs**|Executa uma verificação de sintaxe.|
|**/?**|Exibe um resumo da sintaxe de linha de comando ML.|

*filename*<br/>
O nome do arquivo.

*linkoptions*<br/>
As opções de link.  Ver [opções de vinculador](../../build/reference/linker-options.md) para obter mais informações.

## <a name="remarks"></a>Comentários

Algumas opções de linha de comando ML e ML64 são minúsculas de posicionamento. Por exemplo, porque ML e ML64 podem aceitar vários **/c** opções, qualquer correspondente **/Fo** opções devem ser especificadas antes **/c**. O exemplo de linha de comando a seguir ilustra uma especificação de arquivo de objeto para cada especificação de arquivo do assembly:

**/Fo ml.exe a1.obj /c a.asm /Fo b1.obj /c b.asm**

## <a name="environment-variables"></a>Variáveis de ambiente

|Variável|Descrição|
|--------------|-----------------|
|INCLUDE|Especifica o caminho de pesquisa para arquivos de inclusão.|
|ML|Especifica as opções de linha de comando padrão.|
|TMP|Especifica o caminho para arquivos temporários.|

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>
[Referência do Microsoft Macro Assembler](../../assembler/masm/microsoft-macro-assembler-reference.md)<br/>