---
title: Tipos de arquivo editáveis para recursos (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.resource
helpviewer_keywords:
- file types [C++], for resources
- resources [C++], editing
- files [C++], editable types
- resource editing
ms.assetid: c40f9204-f2f2-400b-9f53-53b7bf291356
ms.openlocfilehash: 9f688c144a3453c2de849b36f34f6a465e3dfeae
ms.sourcegitcommit: 5a7dbd640376e13379f5d5b2cf66c4842e5e737b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/08/2019
ms.locfileid: "55905713"
---
# <a name="editable-file-types-for-resources-c"></a>Tipos de arquivo editáveis para recursos (C++)

Você pode abrir os seguintes tipos de arquivos e editar os recursos que eles contêm.

|Nome do arquivo|Descrição|
|---------------|-----------------|
|.rc|Arquivos de script de recurso.|
|.rct|Arquivos de modelo de recurso.|
|.res|Arquivos de recursos.|
|.resx|Arquivos de recurso gerenciado.|
|.exe|Arquivos executáveis.|
|.dll|Arquivos de biblioteca de vínculo dinâmico.|
|. bmp,. ico,. dib e. cur|Arquivos de bitmap, ícone, barra de ferramentas e cursor.|

## <a name="files-affected-by-resource-editing"></a>Arquivos afetados pela edição de recurso

Ambiente do Visual Studio funciona com os arquivos mostrados na tabela a seguir durante a sessão de edição do recurso.

|Nome do arquivo|Descrição|
|---------------|-----------------|
|Resource.h|Arquivo de cabeçalho gerado pelo ambiente de desenvolvimento. contém definições de símbolo. (Inclui esse arquivo no controle de origem).|
|Filename.aps|Versão binária do arquivo de script de recurso atual; usado para o carregamento rápido.<br /><br /> Os editores de recursos não leem diretamente os arquivos. rc ou Resource. h. O compilador de recurso compila-os em arquivos de .aps, que são consumidos pelos editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos. Como com um normal de processo de compilação, as informações que não seja simbólicas (por exemplo, comentários) são descartadas durante o processo de compilação. Sempre que o arquivo .aps obtém fora de sincronia com o arquivo. RC, o arquivo. rc for gerado novamente (por exemplo, quando você salva, o editor de recurso substitui o arquivo. RC e o arquivo Resource h). Todas as alterações para os próprios recursos permanecerão incorporadas no arquivo. RC, mas comentários sempre serão perdidos depois que o arquivo. RC é substituído. Para obter informações sobre como preservar comentários, consulte [incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md). (Normalmente, você não deve incluir o arquivo .aps no controle de origem.)|
|.rc|Arquivo de script de recurso que contém um script para os recursos em seu projeto atual. Esse arquivo é substituído pelo arquivo .aps sempre que você salva. (Inclui esse arquivo no controle de origem).|

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)