---
title: /ALLOWISOLATION (pesquisa de manifesto)
ms.date: 11/04/2016
f1_keywords:
- /ALLOWISOLATION
- VC.Project.VCLinkerTool.AllowIsolation
helpviewer_keywords:
- -ALLOWISOLATION linker option
- /ALLOWISOLATION linker option
ms.assetid: 6d41851e-b3c1-4bdf-beaa-031773089d6f
ms.openlocfilehash: 7c799f3d44428643bccc2869255ffa4e9d194d70
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493130"
---
# <a name="allowisolation-manifest-lookup"></a>/ALLOWISOLATION (pesquisa de manifesto)

Especifica o comportamento da pesquisa de manifesto.

## <a name="syntax"></a>Sintaxe

```
/ALLOWISOLATION[:NO]
```

## <a name="remarks"></a>Comentários

**/ALLOWISOLATION: não** indica que as DLLs são carregadas como se não houvesse nenhum manifesto e faz com que `IMAGE_DLLCHARACTERISTICS_NO_ISOLATION` o vinculador defina o bit `DllCharacteristics` no campo do cabeçalho opcional.

**/ALLOWISOLATION** faz com que o sistema operacional faça pesquisas e cargas de manifesto.

**/ALLOWISOLATION** é o padrão.

Quando o isolamento estiver desabilitado para um executável, o carregador do Windows não tentará localizar um manifesto do aplicativo para o processo recém-criado. O novo processo não terá um contexto de ativação padrão, mesmo que haja um manifesto dentro do executável ou colocado no mesmo diretório que o executável com o nome <em>executável-Name</em> **. exe. manifest**.

Para obter mais informações, consulte [referência de arquivos de manifesto](/windows/win32/SbsCs/manifest-files-reference).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de Propriedade do**arquivo de manifesto** do**vinculador** > de **Propriedades** > de configuração.

1. Modifique a propriedade **permitir isolamento** .

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
