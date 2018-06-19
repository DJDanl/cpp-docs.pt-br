---
title: 'Como: compilar componentes COM sem registro | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- COM components, registration-free
ms.assetid: 7e585d6a-0314-45b2-8f1b-cae9ac4df037
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e54327344d61cc70e68b528c5f88f3d30f5d185a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32367853"
---
# <a name="how-to-build-registration-free-com-components"></a>Como compilar componentes COM sem registro
OS componentes com sem registro são componentes COM que tenham manifestos incorporados as DLLs.  
  
### <a name="to-build-manifests-into-com-components"></a>Para criar os manifestos em componentes COM  
  
1.  Abra as páginas de propriedades do projeto para o componente COM.  
  
2.  Expanda o **propriedades de configuração** nó e, em seguida, expanda o **ferramenta de manifesto** nó.  
  
3.  Selecione o **de entrada e saída** página de propriedades e defina o **Inserir manifesto** propriedade igual a **Sim**.  
  
4.  Clique em **OK**.  
  
5.  Compile a solução.  
  
## <a name="see-also"></a>Consulte também  
 [Aplicativos isolados](http://msdn.microsoft.com/library/aa375190)   
 [Sobre Assemblies lado a lado](http://msdn.microsoft.com/library/ff951640)   
 [Como compilar aplicativos isolados para consumir componentes COM](../build/how-to-build-isolated-applications-to-consume-com-components.md)