---
title: componente
ms.date: 04/08/2019
f1_keywords:
- vc-pragma.component
- component_CPP
helpviewer_keywords:
- component pragma
- pragmas, component
ms.assetid: 7b66355e-3201-4c14-8190-f4a2a81a604a
ms.openlocfilehash: 4870860650a39d27639ad18100ba37ba14aa15c0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62366908"
---
# <a name="component"></a>componente

Controla a coleção de informações de procura ou informações sobre dependências nos arquivos de origem.

## <a name="syntax"></a>Sintaxe

> **#pragma component( browser,** { **on** | **off** }[**,** **references** [**,** *name* ]] **)** \
> **#pragma component( minrebuild, on** | **off )** \
> **#pragma component( mintypeinfo, on** | **off )**

## <a name="remarks"></a>Comentários

### <a name="browser"></a>Navegador

Você pode ativar ou desativar a coleta e pode especificar nomes a serem ignorados à medida que as informações são coletadas.

O uso de on ou off controla a coleta de informações de navegação do pragma em diante. Por exemplo:

```cpp
#pragma component(browser, off)
```

interrompe a coleta de informações de navegação pelo compilador.

> [!NOTE]
> Para ativar a coleta de informações de procura com esse pragma [informações de pesquisa devem ser habilitadas primeiro](../build/reference/building-browse-information-files-overview.md).

O `references` opção pode ser usada com ou sem o *nome* argumento. Usando o `references` sem *nome* ativa ou desativa a coleta de referências (outras informações de navegação continuam a ser coletado, porém). Por exemplo:

```cpp
#pragma component(browser, off, references)
```

interrompe a coleta de informações sobre referências pelo compilador.

Usando o `references` com *nome* e `off` impede que as referências a *nome* apareça na janela de informações de procura. Use essa sintaxe para ignorar nomes e tipos nos quais você não está interessado e para reduzir o tamanho dos arquivos de informações de navegação. Por exemplo:

```cpp
#pragma component(browser, off, references, DWORD)
```

ignora referências a DWORD a partir desse ponto em diante. Você pode ativar a coleta de referências para DWORD novamente usando `on`:

```cpp
#pragma component(browser, on, references, DWORD)
```

Isso é a única maneira de retomar a coleta de referências a *nome*; você deve ativar explicitamente qualquer *nome* que você tiver desativado.

Para impedir que o pré-processador expanda *nome* (por exemplo, expandindo NULL como 0), coloque aspas ao redor dela:

```cpp
#pragma component(browser, off, references, "NULL")
```

### <a name="minimal-rebuild"></a>Recompilação mínima

Preteridas [/Gm (habilitar recompilação mínima)](../build/reference/gm-enable-minimal-rebuild.md) recurso exige que o compilador para criar e armazenar C++ classe informações de dependência, que usa o espaço em disco. Para economizar espaço em disco, você pode usar `#pragma component( minrebuild, off )` sempre que você não precisará coletar informações sobre dependências, por exemplo, em arquivos de cabeçalho inalterados. Inserir `#pragma component(minrebuild, on)` depois de volta em classes inalteradas para reativar a coleção de dependência.

### <a name="reduce-type-information"></a>Reduzir informações de tipo

O `mintypeinfo` opção reduz as informações de depuração para a região especificada. O volume dessas informações é considerável, afetando arquivos .pdb e .obj. Não é possível depurar classes e estruturas na região de mintypeinfo. O uso da opção mintypeinfo pode ser útil para evitar o seguinte aviso:

```cmd
LINK : warning LNK4018: too many type indexes in PDB "filename", discarding subsequent type information
```

Para obter mais informações, consulte o [/Gm (habilitar recompilação mínima)](../build/reference/gm-enable-minimal-rebuild.md) opção de compilador.

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)