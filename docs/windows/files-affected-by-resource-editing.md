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
ms.openlocfilehash: b165dca13e30e12e1a4fdc85056920b7c10ee586
ms.sourcegitcommit: d06966efce25c0e66286c8047726ffe743ea6be0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/19/2018
ms.locfileid: "36238650"
---
# <a name="files-affected-by-resource-editing"></a>Arquivos afetados pela edição de recurso
Ambiente do Visual Studio funciona com os arquivos mostrados na tabela a seguir durante a sessão de edição de recurso.  
  
|Nome do arquivo|Descrição|  
|---------------|-----------------|  
|Resource.h|Arquivo de cabeçalho gerado pelo ambiente de desenvolvimento; contém as definições de símbolo. (Incluir esse arquivo no controle de origem).|  
|Filename.APs|Versão binária do arquivo de script de recurso atual; usado para o carregamento rápido.<br /><br /> Os editores de recursos não leia arquivos. rc ou resource.h diretamente. O compilador de recurso compila em arquivos de .aps, que são consumidos por editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos. Como o processo de compilação com um normal, as informações que não seja simbólicas (por exemplo, comentários) são descartadas durante o processo de compilação. Sempre que o arquivo .aps fica fora de sincronia com o arquivo. RC, o arquivo. RC é gerada novamente (por exemplo, quando você salva, o editor de recurso substitui o arquivo. RC e o arquivo resource.h). As alterações aos recursos próprios permanecerá incorporadas no arquivo. RC, mas comentários sempre será perdidos quando o arquivo. RC é substituído. Para obter informações sobre como preservar comentários, consulte [incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md). (Normalmente, você não deve incluir o arquivo .aps no controle de origem.)|  
|. rc|Arquivo de script de recurso que contém o script para os recursos em seu projeto atual. Esse arquivo é substituído pelo arquivo .aps sempre que você salvar. (Incluir esse arquivo no controle de origem).|  
  

  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)