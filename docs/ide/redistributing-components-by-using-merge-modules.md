---
title: "Redistribuindo componentes usando módulos de mesclagem | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- merge modules, using
- redistributing applications, using merge modules
ms.assetid: 93b84211-bf9b-4a78-9f22-474ac2ef7840
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 093c732563844b14a3f99662150d4db9b2fac1fb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="redistributing-components-by-using-merge-modules"></a>Redistribuindo componentes usando módulos de mesclagem
O Visual Studio inclui [Mesclar módulos](http://msdn.microsoft.com/library/aa367434) para cada componente do Visual C++ está licenciado para ser redistribuído com um aplicativo. Quando um módulo de mesclagem é compilado em um arquivo de instalação do Windows Installer, ele permite a implantação de DLLs específicas para computadores que tenham uma plataforma específica. No arquivo de instalação, especifique que os módulos de mesclagem são pré-requisitos para seu aplicativo. Quando o Visual Studio está instalado, os módulos de mesclagem são instalados em \Program Comuns\Merge módulos\\. (Somente sem depuração versões de DLLs do Visual C++ podem ser redistribuídas.) Para obter mais informações e um link para uma lista de módulos de mesclagem que estão licenciados para redistribuição, consulte [arquivos de redistribuição do Visual C++](../ide/redistributing-visual-cpp-files.md).  
  
 Você pode usar módulos de mesclagem para habilitar a instalação de DLLs redistribuíveis de Visual C++ para a pasta %SYSTEMROOT%\system32\. (O próprio visual Studio usa essa técnica). No entanto, a instalação nessa pasta falhará a menos que o usuário instalador tenha direitos de administrador.  
  
 É recomendável não usar módulos de mesclagem, exceto quando você não precisa reparar o aplicativo e não depende de mais de uma versão das DLLs. Os módulos de mesclagem para versões diferentes da mesma DLL não podem ser incluídos em um instalador, e os módulos de mesclagem dificultam o reparo de DLLs independentemente de seu aplicativo. Em vez disso, recomendamos que você instale um pacote redistribuível do Visual C++.  
  
## <a name="see-also"></a>Consulte também  
 [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md)