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
ms.openlocfilehash: 0a52e9c9dcd53b01f17dc36825732b34771c75bb
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492622"
---
# <a name="section-specify-section-attributes"></a>/SECTION (especificar atributos de seção)

> **/Section:** _nome_, [[ **!** ] {**DEKPRSW**}] [ **, Align =** _Number_]

## <a name="remarks"></a>Comentários

A opção **/Section** altera os atributos de uma seção, substituindo os atributos definidos quando o arquivo. obj da seção foi compilado.

Uma *seção* em um arquivo executável portátil (PE) é um bloco de memória contíguo nomeado que contém o código ou os dados. Algumas seções contêm código ou dados que seu programa declarou e usa diretamente, enquanto outras seções de dados são criadas para você pelo vinculador e pelo Gerenciador de biblioteca (lib. exe) e contêm informações essenciais para o sistema operacional. Para obter mais informações, consulte [formato PE](/windows/win32/Debug/pe-format).

Especifique dois-pontos (:) e um *nome*de seção. O *nome* diferencia maiúsculas de minúsculas.

Não use os nomes a seguir, pois eles entram em conflito com nomes padrão. Por exemplo,. sdata é usado em plataformas RISC:

- . Arch

- . BSS

- . Data

- .edata

- .idata

- .pdata

- .rdata

- . realocação

- . rsrc

- . seção sbss

- .sdata

- .srdata

- .text

- .xdata

Especifique um ou mais atributos para a seção. Os caracteres de atributo, listados abaixo, não diferenciam maiúsculas de minúsculas. Você deve especificar todos os atributos que deseja que a seção tenha; um caractere de atributo omitido faz com que esse bit de atributo seja desativado. Se você não especificar R, W ou E, o status de leitura, gravação ou executável existente permanecerá inalterado.

Para negar um atributo, preceda seu caractere com um ponto de exclamação (!). Os significados dos caracteres de atributo são mostrados nesta tabela:

|Caractere|Atributo|Significado|
|---------------|---------------|-------------|
|E|Executar|A seção é executável|
|R|Ler|Permite operações de leitura em dados|
|W|Write|Permite operações de gravação em dados|
|S|Compartilhado|Compartilha a seção entre todos os processos que carregam a imagem|
|D|Descartado|Marca a seção como descartada|
|K|Armazenável em cache|Marca a seção como não armazenável em cache|
|P|Paginável|Marca a seção como não paginável|

K e P são incomuns, pois os sinalizadores de seção que correspondem a eles são usados no sentido negativo. Se você especificar um deles na seção. Text usando a opção **/Section:. Text, K** , não haverá nenhuma diferença nos sinalizadores de seção quando você executar [DUMPBIN](dumpbin-options.md) com a opção [/Headers](headers.md) ; a seção já estava armazenada em cache implicitamente. Para remover o padrão, especifique **/Section:. Text,!** Em vez disso. DUMPBIN revela características da seção, incluindo "não armazenado em cache".

Uma seção no arquivo PE que não tem o conjunto de E, R ou W é provavelmente inválida.

O argumento **align =** _Number_ permite especificar um valor de alinhamento para uma determinada seção. O argumento _Number_ está em bytes e deve ser uma potência de dois. Consulte [/align](align-section-alignment.md) para obter mais informações.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Escolha a página de propriedade da**linha de comando** do**vinculador** > de **Propriedades** > de configuração.

1. Insira a opção na caixa **Opções adicionais** . Escolha **OK** ou **aplicar** para aplicar a alteração.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
