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
ms.openlocfilehash: 1eaf9417f4d2b3b825933589556055772b84e057
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43197407"
---
# <a name="how-to-build-registration-free-com-components"></a>Como compilar componentes COM sem registro
Componentes do COM sem registro são componentes COM que tem criados as DLLs de manifestos.  
  
### <a name="to-build-manifests-into-com-components"></a>Para compilar manifestos em componentes COM  
  
1.  Abra as páginas de propriedades do projeto para o componente COM.  
  
2.  Expanda o **propriedades de configuração** nó e, em seguida, expanda o **ferramenta de manifesto** nó.  
  
3.  Selecione o **de entrada e saída** página de propriedades e defina as **Inserir manifesto** propriedade igual a **Sim**.  
  
4.  Clique em **OK**.  
  
5.  Compile a solução.  
  
## <a name="see-also"></a>Consulte também  
 [Aplicativos isolados](/windows/desktop/SbsCs/isolated-applications)   
 [Sobre Assemblies lado a lado](/windows/desktop/SbsCs/about-side-by-side-assemblies-)   
 [Como compilar aplicativos isolados para consumir componentes COM](../build/how-to-build-isolated-applications-to-consume-com-components.md)