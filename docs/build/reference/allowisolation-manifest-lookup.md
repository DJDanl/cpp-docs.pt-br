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
ms.openlocfilehash: 62f467ff467d785d17601737436e0eb1ff972f37
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43205487"
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
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **o arquivo de manifesto** página de propriedades.  
  
5.  Modificar a **permitir isolamento** propriedade.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)