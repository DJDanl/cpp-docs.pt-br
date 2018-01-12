---
title: Redistribuindo controles ActiveX do Visual C++ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- controls [C++], redistributing
- controls [C++], distributing
ms.assetid: eefbb7e4-d28c-4c35-98bf-d9540cfaae83
caps.latest.revision: "18"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c520d365a259c36baab8edeb9049aab9ac89925a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="redistributing-visual-c-activex-controls"></a>Redistribuindo controles ActiveX do Visual C++
Visual C++ 6.0 fornece controles ActiveX que você pode usar em aplicativos que você, em seguida, redistribuir. Esses controles não estão mais incluídos no Visual C++. Por que os contratos de licença para o Visual C++ 6.0, você pode redistribuir esses controles com aplicativos desenvolvidos no Visual C++.  
  
> [!NOTE]
>  Não há suporte para o Visual C++ 6.0 pela Microsoft.  
  
 Para obter uma lista dos controles ActiveX do Visual C++ 6.0 redistribuíveis, consulte Common\Redist\Redist.txt no disco 1 do CD do produto do Visual C++ 6.0.  
  
 Quando a distribuição de aplicativos, deve instalar e registrar o. ocx para o controle ActiveX (usando o Regsvr32.exe). Além disso, você deve verificar se que o computador de destino tem as versões atuais dos seguintes arquivos de sistema (um asterisco indica que o arquivo precisa ser registrado):  
  
-   Asycfilt  
  
-   Comcat *  
  
-   Oleaut32.dll *  
  
-   OLEPRO32 *  
  
-   Stdole2  
  
 Se essas DLLs não estão disponíveis no sistema de destino, você precisa obtê-los atualizados usando o mecanismo indicado para atualizar o sistema operacional correspondente. Você pode baixar os service packs mais recentes para sistemas operacionais Windows [http://windowsupdate.microsoft.com](http://windowsupdate.microsoft.com).  
  
 Se seu aplicativo usa um dos controles ActiveX que se conecta a um banco de dados, você deve ter o Microsoft Data Access Components (MDAC) instalado no sistema de destino. Para obter mais informações, consulte [redistribuindo arquivos de suporte do banco de dados](../ide/redistributing-database-support-files.md).  
  
 Ao usar um controle ActiveX que se conecta a um banco de dados, você também precisa replicar o nome da fonte de dados no computador de destino. Você pode fazer isso programaticamente com funções como `ConfigDSN`.  
  
 Alguns controles ActiveX redistribuíveis têm dependências adicionais. Para cada arquivo. ocx na pasta Os\System no CD do produto do Visual C++ 6.0, também há um arquivo. DEP. Para cada arquivo. ocx que deseja redistribuir, procure uma ou mais entradas usa no arquivo. DEP correspondente. Se um arquivo estiver listado, certifique-se de que o arquivo está no computador de destino. Quaisquer DLLs suporte diretamente a um arquivo. ocx precisam ser registrados. (Para Regsvr32.exe seja bem-sucedida, o computador de destino deve primeiro conter todas as DLLs estaticamente carrega o controle.) Além disso, se uma DLL que está listada como uma dependência também tem um arquivo. DEP na pasta Os\System no CD do Visual C++ 6.0, você também deve investigar esse arquivo. DEP usa entradas.  
  
## <a name="see-also"></a>Consulte também  
 [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md)