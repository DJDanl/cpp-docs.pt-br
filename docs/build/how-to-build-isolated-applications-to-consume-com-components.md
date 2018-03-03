---
title: 'Como: compilar aplicativos isolados para consumir componentes COM | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- isolated applications [C++]
ms.assetid: 04587547-1174-44ab-bd99-1292358fba20
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: aaeef56f122d10f983313ab1c839db40f4e92aa4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-build-isolated-applications-to-consume-com-components"></a>Como compilar aplicativos isolados para consumir componentes COM
Aplicativos isolados são aplicativos que têm manifestos incorporados ao programa. Você pode criar aplicativos isolados para consumir componentes COM.  
  
### <a name="to-add-com-references-to-manifests-of-isolated-applications"></a>Para adicionar referências de COM para manifestos de aplicativos isolados  
  
1.  Abra as páginas de propriedades do projeto para o aplicativo a isoladas.  
  
2.  Expanda o **propriedades de configuração** nó e, em seguida, expanda o **ferramenta de manifesto** nó.  
  
3.  Selecione o **isolado COM** página de propriedades e defina o **nome de arquivo do componente** propriedade para o nome do componente COM que você deseja que os aplicativos isolados para consumir.  
  
4.  Clique em **OK**.  
  
### <a name="to-build-manifests-into-isolated-applications"></a>Para criar os manifestos em aplicativos isolados  
  
1.  Abra as páginas de propriedades do projeto para o aplicativo a isoladas.  
  
2.  Expanda o **propriedades de configuração** nó e, em seguida, expanda o **ferramenta de manifesto** nó.  
  
3.  Selecione o **de entrada e saída** página de propriedades e defina o **Inserir manifesto** propriedade igual a **Sim**.  
  
4.  Clique em **OK**.  
  
5.  Compile a solução.  
  
## <a name="see-also"></a>Consulte também  
 [Aplicativos isolados](http://msdn.microsoft.com/library/aa375190)   
 [Sobre Assemblies lado a lado](http://msdn.microsoft.com/library/ff951640)