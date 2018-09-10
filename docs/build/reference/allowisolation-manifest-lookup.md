---
title: -ALLOWISOLATION (pesquisa de manifesto) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /ALLOWISOLATION
- VC.Project.VCLinkerTool.AllowIsolation
dev_langs:
- C++
helpviewer_keywords:
- -ALLOWISOLATION linker option
- /ALLOWISOLATION linker option
ms.assetid: 6d41851e-b3c1-4bdf-beaa-031773089d6f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c9197e67e46932f08a266258c41dab7922af2900
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44318974"
---
# <a name="allowisolation-manifest-lookup"></a>/ALLOWISOLATION (pesquisa de manifesto)

Especifica o comportamento da pesquisa de manifesto.

## <a name="syntax"></a>Sintaxe

```
/ALLOWISOLATION[:NO]
```

## <a name="remarks"></a>Comentários

**/ALLOWISOLATION:no** indica a DLLs serão carregadas como se houvesse nenhum manifesto e faz com que o vinculador defina o `IMAGE_DLLCHARACTERISTICS_NO_ISOLATION` bit no cabeçalho opcional `DllCharacteristics` campo.

**/ALLOWISOLATION** faz com que o sistema operacional de manifesto cargas e pesquisas.

**/ALLOWISOLATION** é o padrão.

Quando o isolamento é desabilitado por um executável, o carregador do Windows não tentará encontrar um manifesto de aplicativo para o processo recém-criado. O novo processo não terá um contexto de ativação padrão, mesmo se houver um manifesto dentro do executável ou colocada no mesmo diretório que o executável com o nome <em>nome do executável</em>**. manifest**.

Para obter mais informações, consulte [referência de arquivos de manifesto](/windows/desktop/SbsCs/manifest-files-reference).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **o arquivo de manifesto** página de propriedades.

1. Modificar a **permitir isolamento** propriedade.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
