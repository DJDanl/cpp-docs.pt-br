---
title: Redistribuindo componentes usando módulos de mesclagem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- merge modules, using
- redistributing applications, using merge modules
ms.assetid: 93b84211-bf9b-4a78-9f22-474ac2ef7840
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d816d932ce518e006e5537075fe4ac7782362ad4
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43206978"
---
# <a name="redistributing-components-by-using-merge-modules"></a>Redistribuindo componentes usando módulos de mesclagem
O Visual Studio inclui [módulos de mesclagem](/windows/desktop/Msi/about-merge-modules) para cada componente do Visual C++ que é licenciado para ser redistribuído com um aplicativo. Quando um módulo de mesclagem é compilado em um arquivo de instalação do Windows Installer, ele permite a implantação de DLLs específicas para computadores que tenham uma plataforma específica. No arquivo de instalação, especifique que os módulos de mesclagem são pré-requisitos para seu aplicativo. Quando o Visual Studio é instalado, os módulos de mesclagem são instalados em \Arquivos de Programas\Common Files\Merge Modules\\. (Somente as versões sem depuração das DLLs do Visual C++ podem ser redistribuídas.) Para obter mais informações e um link para uma lista de módulos de mesclagem licenciados para redistribuição, confira [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md).  
  
 Use os módulos de mesclagem para habilitar a instalação de DLLs redistribuíveis do Visual C++ na pasta %SYSTEMROOT%\system32\. (O próprio Visual Studio usa essa técnica.) No entanto, a instalação nessa pasta falhará a menos que o usuário instalador tenha direitos de administrador.  
  
 É recomendável não usar módulos de mesclagem, exceto quando você não precisa reparar o aplicativo e não depende de mais de uma versão das DLLs. Os módulos de mesclagem para versões diferentes da mesma DLL não podem ser incluídos em um instalador, e os módulos de mesclagem dificultam o reparo de DLLs independentemente de seu aplicativo. Em vez disso, recomendamos a instalação de um Pacote Redistribuível do Visual C++.  
  
## <a name="see-also"></a>Consulte também  
 [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md)