---
title: "As configurações de projeto ATL padrão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, default configurations
ms.assetid: 7e272722-41af-4330-b965-a6d74ec16880
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 6cad5222fb0d97594d5b13b5cf8903eb2934ee88
ms.openlocfilehash: 41ab65c411bef478d063e5165d3167f58ace37d7
ms.lasthandoff: 02/25/2017

---
# <a name="default-atl-project-configurations"></a>Configurações de projeto padrão ATL
Este tópico compara as configurações do projeto padrão ATL no Visual C++ .NET com as configurações de projeto padrão no Visual C++ 6.0.  
  
## <a name="visual-c-net-default-configurations"></a>Configurações padrão do Visual C++ .NET  
 No Visual C++ .NET, ATL Project Wizard cria duas configurações de projeto por padrão.  
  
### <a name="visual-c-net-configurations"></a>Configurações do Visual C++ .NET  
  
|Configuração|Conjunto de caracteres|Uso da ATL|  
|-------------------|-------------------|----------------|  
|Versão|MBCS|DLL|  
|Depurar|MBCS|DLL|  
  
 **Conjunto de caracteres**, **uso de ATL** e pode ser alterado no **configurações do projeto** diálogo sob o **geral** guia. Você também pode adicionar suas próprias configurações usando o Gerenciador de configuração. Para obter detalhes, consulte [configurações de compilação](/visualstudio/ide/understanding-build-configurations).  
  
## <a name="version-60-default-configurations"></a>Configurações padrão de versão 6.0  
 No Visual C++ versão 6.0, o AppWizard de COM ATL (agora chamado ATL Project Wizard) criado seis configurações de projeto por padrão. As configurações foram variações na versão, depuração, Unicode e uso de configurações do CRT e ATL. Todas essas configurações podem ser duplicadas no Visual C++ .NET usando o Gerenciador de configuração, se desejado.  
  
### <a name="version-60-configurations"></a>Configurações de versão 6.0  
  
|Configuração|Conjunto de caracteres|Uso da ATL|  
|-------------------|-------------------|----------------|  
|Depurar|MBCS|Estático|  
|Depurar Unicode|UNICODE|Estático|  
|Versão mínima de dependência|MBCS|Estático|  
|Versão mínima dependência Unicode|UNICODE|Estático|  
|Tamanho mínimo de versão|MBCS|DLL|  
|Versão Unicode de tamanho mínimo|UNICODE|DLL|  
  
## <a name="see-also"></a>Consulte também  
 [Programando com código ATL e C Run-Time](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Trabalhando com propriedades de projeto](../../ide/working-with-project-properties.md)   
 [Caixa de diálogo Gerenciador de configuração](http://msdn.microsoft.com/en-us/fa182dca-282e-4ae5-bf37-e155344ca18b)   
 [Compilando e criando](/visualstudio/ide/compiling-and-building-in-visual-studio)


