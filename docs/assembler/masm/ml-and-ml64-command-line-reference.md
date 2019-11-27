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
ms.openlocfilehash: 470cad1be6fe314fde89ee144a8935664ead5953
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74397204"
---
# <a name="ml-and-ml64-command-line-reference"></a>Referência de linha de comando ML e ML64

Monta e vincula um ou mais arquivos de origem de linguagem de assembly. As opções de linha de comando diferenciam maiúsculas de minúsculas.

Para obter mais informações sobre o ml64. exe, consulte [MASM para x64 (ml64. exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

## <a name="syntax"></a>Sintaxe

> ML \[*Opções*] *nome do arquivo* \[ \[*Opções*] *nome do arquivo*]
>
> ML64 \[*Opções*] *nome do arquivo* \[ \[*Opções*] *nome do arquivo*]... \[/link *linkoptions*]

### <a name="parameters"></a>Parâmetros

*opções*\
As opções listadas na tabela a seguir.

|Opção|Action|
|------------|------------|
|**/AT**|Habilita o mínimo de suporte a modelos de memória. Habilita mensagens de erro para construções de código que violam os requisitos para arquivos de formato. com. Observe que isso não é equivalente ao [. ](../../assembler/masm/dot-model.md)Diretiva **Tiny** do modelo.<br /><br /> Não disponível em ml64. exe.|
|*Nome de arquivo* /BL|Seleciona um vinculador alternativo.|
|**/c**|Somente monta. Não é vinculado.|
|**/COFF**|Gera o tipo COFF (Common Object File Format) do módulo de objeto. Geralmente necessário para o desenvolvimento da linguagem de assembly do Win32.<br /><br /> Não disponível em ml64. exe.|
|**/Cp**|Preserva o caso de todos os identificadores de usuário.|
|**/Cu**|Mapeia todos os identificadores para letras maiúsculas (padrão).<br /><br /> Não disponível em ml64. exe.|
|**/CX**|Preserva maiúsculas e minúsculas em símbolos públicos e extern.|
|**/D** *Symbol*⟦ =*Value*⟧|Define uma macro de texto com o nome fornecido. Se o *valor* estiver ausente, ele ficará em branco. Vários tokens separados por espaços devem ser colocados entre aspas.|
|**/EP**|Gera uma listagem de origem pré-processada (enviada para STDOUT). Consulte **/SF**.|
|**/errorreport** [ **nenhum** &#124; **Enviar** **prompt** &#124; da **fila** &#124; ]|Se o ml. exe ou ml64. exe falhar em tempo de execução, você poderá usar **/errorreport** para enviar informações à Microsoft sobre esses erros internos.<br /><br /> Para obter mais informações sobre **/errorreport**, consulte [/errorReport (relatar erros de compilador interno)](../../build/reference/errorreport-report-internal-compiler-errors.md).|
|**/F** *hexnum*|Define o tamanho da pilha para *hexnum* bytes (isso é o mesmo que **/link/Stack**:*Number*). O valor deve ser expresso em notação hexadecimal. Deve haver um espaço entre **/f** e *hexnum*.|
|*Nome de arquivo* /FE|Nomeia o arquivo executável.|
|**/Fl**⟦*filename*⟧|Gera uma listagem de código montada. Consulte **/SF**.|
|**/FM**⟦*filename*⟧|Cria um arquivo de mapa do vinculador.|
|**/Fo** *filename*|Nomeia um arquivo de objeto. Consulte a seção comentários para obter mais informações.|
|**/FPi**|Gera correções de emulador para aritmética de ponto flutuante (somente linguagem mista).<br /><br /> Não disponível em ml64. exe.|
|**/Fr**⟦*filename*⟧|Gera um arquivo. sbr do navegador de origem.|
|**/Fr**⟦*filename*⟧|Gera uma forma estendida de um arquivo. sbr do navegador de origem.|
|**/GC**|Especifica o uso de convenções de nomenclatura e de chamada de função estilo FORTRAN ou Pascal. O mesmo que o **idioma da opção: Pascal**.<br /><br /> Não disponível em ml64. exe.|
|**/Gd**|Especifica o uso da chamada de função C-Style e das convenções de nomenclatura. O mesmo que o **idioma da opção: C**.<br /><br /> Não disponível em ml64. exe.|
|**/GZ**|Especifica o uso de __stdcall de chamadas de função e convenções de nomenclatura.  Mesmo que o **idioma da opção: a chamada**.<br /><br /> Não disponível em ml64. exe.|
|**/H** *número*|Restringe nomes externos para números significativos de caracteres. O padrão é 31 caracteres.<br /><br /> Não disponível em ml64. exe.|
|**/help**|Chama QuickHelp para obter ajuda sobre ML.|
|*Nome do caminho* /i|Define o caminho para o arquivo de inclusão. É permitido um máximo de 10 opções **/i** .|
|**/nologo**|Suprime mensagens para o assembly bem-sucedido.|
|**/omf**|Gera o tipo de OMF (formato de arquivo do módulo de objeto) do módulo de objeto.  **/OMF** implica **/c**; O ML. exe não dá suporte à vinculação de objetos OMF.<br /><br /> Não disponível em ml64. exe.|
|**/SA**|Ativa a listagem de todas as informações disponíveis.|
|**/SAFESEH**|Marca o objeto como não contendo manipuladores de exceção ou que contenham manipuladores de exceção que são todos declarados com [. SAFESEH](../../assembler/masm/dot-safeseh.md).<br /><br /> Não disponível em ml64. exe.|
|**/Sf**|Adiciona a lista de primeiras passagens ao arquivo de listagem.|
|*Largura* de/SL|Define a largura da linha da listagem de origem em caracteres por linha. O intervalo é de 60 a 255 ou 0. O padrão é 0. Igual à largura [da página](../../assembler/masm/page.md) .|
|**/Sn**|Desativa a tabela de símbolos ao produzir uma listagem.|
|*Comprimento* de/SP|Define o comprimento da página da listagem de origem em linhas por página. O intervalo é de 10 a 255 ou 0. O padrão é 0. Igual ao comprimento [da página](../../assembler/masm/page.md) .|
|*Texto* /SS|Especifica o texto para a listagem de origem. O mesmo que o texto do [subtítulo](../../assembler/masm/subtitle.md) .|
|**/St** *texto*|Especifica o título da listagem de origem. O mesmo que o texto do [título](../../assembler/masm/title.md) .|
|**/Sx**|Ativa falsos condicionais na listagem.|
|*Nome de arquivo* /ta|Monta o arquivo de origem cujo nome não termina com a extensão. asm.|
|**/w**|O mesmo que **/W0/WX**.|
|*Nível* de/w|Define o nível de aviso, em que *nível* = 0, 1, 2 ou 3.|
|**/WX**|Retornará um código de erro se os avisos forem gerados.|
|**/X**|Ignorar caminho de ambiente de inclusão.|
|**/Zd**|Gera informações de número de linha no arquivo de objeto.|
|**/ZF**|Torna todos os símbolos públicos.|
|**/Zi**|Gera informações de CodeView no arquivo de objeto.|
|**/ZM**|Habilita a opção**M510** para obter a compatibilidade máxima com o MASM 5,1.<br /><br /> Não disponível em ml64. exe.|
|**/ZP***alinhamento*⟦ ⟧|Empacota estruturas no limite de bytes especificado. O *alinhamento* pode ser 1, 2 ou 4.|
|**/ZS**|Executa apenas uma verificação de sintaxe.|
|**/?**|Exibe um resumo da sintaxe de linha de comando do ML.|

*nome de arquivo*\
O nome do arquivo.

\ de *linkoptions*
As opções de link.  Consulte [Opções do vinculador](../../build/reference/linker-options.md) para obter mais informações.

## <a name="remarks"></a>Comentários

Algumas opções de linha de comando para ML e ML64 são sensíveis a posicionamento. Por exemplo, como ML e ML64 podem aceitar várias opções **/c** , todas as opções **/fo** correspondentes devem ser especificadas antes de **/c**. O exemplo de linha de comando a seguir ilustra uma especificação de arquivo de objeto para cada especificação de arquivo de assembly:

**ml. exe/fo a1. obj/c a. asm/fo B1. obj/c b. asm**

## <a name="environment-variables"></a>Variáveis de ambiente

|Variável|Descrição|
|--------------|-----------------|
|INCLUDE|Especifica o caminho de pesquisa para arquivos de inclusão.|
|ML|Especifica opções de linha de comando padrão.|
|TMP|Especifica o caminho para arquivos temporários.|

## <a name="see-also"></a>Consulte também

[Mensagens de erro do ML](../../assembler/masm/ml-error-messages.md)\
[Referência do Microsoft Macro Assembler](../../assembler/masm/microsoft-macro-assembler-reference.md)
