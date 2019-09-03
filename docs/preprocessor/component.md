---
title: Pragma component
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.component
- component_CPP
helpviewer_keywords:
- component pragma
- pragmas, component
ms.assetid: 7b66355e-3201-4c14-8190-f4a2a81a604a
ms.openlocfilehash: 578c590bdb4223f173e0249c18d0eea4e78a18db
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220468"
---
# <a name="component-pragma"></a>Pragma component

Controla a coleção de informações de procura ou informações de dependência de dentro dos arquivos de origem.

## <a name="syntax"></a>Sintaxe

> **componente #pragma (navegador,** { **on** | **off** } [ **,** **References** [ **,** *Name* ]] **)**  \
> **componente #pragma (minrebuild,** { **on** | **off** } **)**  \
> **componente #pragma (MinTypeInfo,** { **on** | **off** } **)**

## <a name="remarks"></a>Comentários

### <a name="browser"></a>Navegador

Você pode ativar ou desativar a coleta e pode especificar nomes a serem ignorados à medida que as informações são coletadas.

O uso de on ou off controla a coleta de informações de navegação do pragma em diante. Por exemplo:

```cpp
#pragma component(browser, off)
```

interrompe a coleta de informações de navegação pelo compilador.

> [!NOTE]
> Para ativar a coleta de informações de procura com este pragma, [as informações de procura devem ser habilitadas primeiro](../build/reference/building-browse-information-files-overview.md).

A opção References pode ser usada com ou sem o argumento *Name* . O uso de **referências** sem *nome* ativa ou desativa a coleta de referências (outras informações de procura continuam sendo coletadas, no entanto). Por exemplo:

```cpp
#pragma component(browser, off, references)
```

interrompe a coleta de informações sobre referências pelo compilador.

O uso de **referências** com *Name* e **off** impede que referências a *nome* apareçam na janela procurar informações. Use essa sintaxe para ignorar nomes e tipos nos quais você não está interessado e para reduzir o tamanho dos arquivos de informações de navegação. Por exemplo:

```cpp
#pragma component(browser, off, references, DWORD)
```

ignora referências a DWORD desse ponto em diante. Você pode ativar a coleta de referências para o DWORD de volta usando **em**:

```cpp
#pragma component(browser, on, references, DWORD)
```

Essa é a única maneira de retomar as referências de coleta para *Name*; Você deve ativar explicitamente qualquer *nome* que você tenha desativado.

Para impedir que o pré-processador expanda o *nome* (como expandir nulo para 0), coloque aspas em seu lugar:

```cpp
#pragma component(browser, off, references, "NULL")
```

### <a name="minimal-rebuild"></a>Recompilação mínima

O recurso preterido [/GM (habilitar recompilação mínima)](../build/reference/gm-enable-minimal-rebuild.md) requer que o compilador crie C++ e armazene informações de dependência de classe, que ocupam espaço em disco. Para economizar espaço em disco, você pode `#pragma component( minrebuild, off )` usar sempre que não precisar coletar informações de dependência, por exemplo, em arquivos de cabeçalho inalterados. Inserir `#pragma component( minrebuild, on )` depois de alterar as classes para ativar novamente a coleção de dependências.

### <a name="reduce-type-information"></a>Reduzir informações de tipo

A `mintypeinfo` opção reduz as informações de depuração para a região especificada. O volume dessas informações é considerável, afetando arquivos .pdb e .obj. Não é possível depurar classes e estruturas na região de mintypeinfo. O uso da opção mintypeinfo pode ser útil para evitar o seguinte aviso:

```cmd
LINK : warning LNK4018: too many type indexes in PDB "filename", discarding subsequent type information
```

Para obter mais informações, consulte a opção de compilador [/GM (Enable minima REBUILD)](../build/reference/gm-enable-minimal-rebuild.md) .

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
