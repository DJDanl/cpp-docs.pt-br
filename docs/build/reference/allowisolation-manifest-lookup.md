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
ms.openlocfilehash: a0e063aa51e136dfcc7a4445948e8a68d7a99bca
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32369832"
---
# <a name="allowisolation-manifest-lookup"></a>/ALLOWISOLATION (pesquisa de manifesto)
Especifica o comportamento da pesquisa de manifesto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/ALLOWISOLATION[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 **/ALLOWISOLATION:no** indica DLLs são carregadas como se não houve nenhum manifesto e faz com que o vinculador definir o `IMAGE_DLLCHARACTERISTICS_NO_ISOLATION` bit do cabeçalho opcional `DllCharacteristics` campo.  
  
 **/ALLOWISOLATION** faz com que o sistema operacional ao manifesto pesquisas e carrega.  
  
 **/ALLOWISOLATION** é o padrão.  
  
 Quando o isolamento é desabilitado por um executável, o carregador do Windows não tentará localizar um manifesto de aplicativo para o processo criado recentemente. O novo processo não terá um contexto de ativação padrão, mesmo se houver um manifesto dentro do executável ou colocado no mesmo diretório do executável com nome * executável-name ***. manifest**.  
  
 Para obter mais informações, consulte [referência de arquivos de manifesto](http://msdn.microsoft.com/library/aa375632).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **o arquivo de manifesto** página de propriedades.  
  
5.  Modificar o **permitir isolamento** propriedade.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)