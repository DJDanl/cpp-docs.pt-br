---
title: /SECTION (especificar atributos de seção)
ms.date: 12/29/2017
f1_keywords:
- /section
helpviewer_keywords:
- SECTION linker option
- -SECTION linker option
- section attributes
- /SECTION linker option
ms.openlocfilehash: 8fb73043c9c185adee0859bb81098eab022430c2
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57816549"
---
# <a name="section-specify-section-attributes"></a>/SECTION (especificar atributos de seção)

> **/SECTION:**_name_,[[**!**]{**DEKPRSW**}][**,ALIGN=**_number_]

## <a name="remarks"></a>Comentários

O **/seção** opção altera os atributos de uma seção, sobrescrevendo os atributos definidos quando o arquivo. obj para a seção foi compilado.

Um *seção* em um arquivo executável portátil (PE) o arquivo é um bloco nomeado contíguo de memória que contém o código ou dados. Algumas seções contêm código ou dados que seu programa declarados e usa diretamente, enquanto outras seções de dados são criadas para você, o vinculador e o Gerenciador de biblioteca (lib.exe) e contêm informações vitais para o sistema operacional. Para obter mais informações, consulte [formato PE](/windows/desktop/Debug/pe-format).

Especifique um dois-pontos (:) e uma seção *nome*. O *nome* diferencia maiusculas de minúsculas.

Não use os seguintes nomes, pois eles entram em conflito com os nomes padrão. Por exemplo,. sdata é usado nas plataformas RISC:

- .arch

- BSS

- .data

- .edata

- .idata

- .pdata

- .rdata

- .reloc

- .rsrc

- .sbss

- .sdata

- .srdata

- .text

- .xdata

Especifique um ou mais atributos para a seção. Os caracteres de atributo, listados abaixo, não diferenciam maiusculas de minúsculas. Você deve especificar todos os atributos que você deseja que a seção ter; um caractere de atributo omitido faz com que esse bit de atributo ser desligado. Se você não especificar a gravação de R, W ou E, a leitura existente, ou executável status permanece inalterado.

Para negar a um atributo, preceda seu caractere com um ponto de exclamação (!). Os significados dos caracteres de atributo são mostrados nesta tabela:

|Caractere|Atributo|Significado|
|---------------|---------------|-------------|
|E|Executar|A seção é executável|
|R|Ler|Permite operações de leitura em dados|
|W|Write|Permite operações de gravação em dados|
|S|Compartilhado|Compartilha a seção entre todos os processos que carregam a imagem|
|D|Descartável|Marca a seção como descartável|
|M|Armazenáveis em cache|Marca a seção como não armazenável em cache|
|P|Paginável|Marca a seção como não paginável|

K e P é incomuns em que os sinalizadores de seção que correspondem a eles são usados no sentido de negativo. Se você especifica um na seção de. Text usando o **/SECTION:.text, K** opção, não há nenhuma diferença nos sinalizadores de seção quando você executa [DUMPBIN](dumpbin-options.md) com o [/HEADERS](headers.md)opção; a seção já implicitamente foi armazenado em cache. Para remover o padrão, especifique **/SECTION:.text,! K** em vez disso. Opção DUMPBIN revela as características de seção, incluindo "Não armazenado em cache."

Uma seção no arquivo PE que não tenha E, R ou W definido é provavelmente inválida.

O **ALIGN =**_número_ argumento permite que você especifique um valor de alinhamento para uma determinada seção. O _número_ argumento é em bytes e deve ser uma potência de dois. Ver [/ALINHAR](align-section-alignment.md) para obter mais informações.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Escolha o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira a opção na **opções adicionais** caixa. Escolher **Okey** ou **aplicar** para aplicar a alteração.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
