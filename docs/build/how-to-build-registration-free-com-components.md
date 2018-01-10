---
title: 'Como: compilar componentes COM sem registro | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: COM components, registration-free
ms.assetid: 7e585d6a-0314-45b2-8f1b-cae9ac4df037
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 018a3ba707f4c5cff73b5a5c54f82400a79a8d46
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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