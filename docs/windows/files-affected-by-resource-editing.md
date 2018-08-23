---
title: Arquivos afetados pela edição de recurso | Microsoft Docs
ms.custom: ''
ms.date: 06/18/2018
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- resource editing
- resources [Visual Studio], editing
ms.assetid: d0820df1-ba84-40ac-bce9-29ea5ee7e3f8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: cec210476a8204a65e8abf2188e47864d010e6d7
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42585437"
---
# <a name="files-affected-by-resource-editing"></a>Arquivos afetados pela edição de recurso

Ambiente do Visual Studio funciona com os arquivos mostrados na tabela a seguir durante a sessão de edição do recurso.

|Nome do arquivo|Descrição|
|---------------|-----------------|
|Resource.h|Arquivo de cabeçalho gerado pelo ambiente de desenvolvimento. contém definições de símbolo. (Inclui esse arquivo no controle de origem).|
|Filename.APs|Versão binária do arquivo de script de recurso atual; usado para o carregamento rápido.<br /><br /> Os editores de recursos não leem diretamente os arquivos. rc ou Resource. h. O compilador de recurso compila-os em arquivos de .aps, que são consumidos pelos editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos. Como com um normal de processo de compilação, as informações que não seja simbólicas (por exemplo, comentários) são descartadas durante o processo de compilação. Sempre que o arquivo .aps obtém fora de sincronia com o arquivo. RC, o arquivo. rc for gerado novamente (por exemplo, quando você salva, o editor de recurso substitui o arquivo. RC e o arquivo Resource h). Todas as alterações para os próprios recursos permanecerão incorporadas no arquivo. RC, mas comentários sempre serão perdidos depois que o arquivo. RC é substituído. Para obter informações sobre como preservar comentários, consulte [incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md). (Normalmente, você não deve incluir o arquivo .aps no controle de origem.)|
|. rc|Arquivo de script de recurso que contém um script para os recursos em seu projeto atual. Esse arquivo é substituído pelo arquivo .aps sempre que você salva. (Inclui esse arquivo no controle de origem).|

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)