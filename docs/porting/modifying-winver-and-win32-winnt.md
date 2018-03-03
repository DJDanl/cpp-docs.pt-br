---
title: Modificando WINVER e _WIN32_WINNT | Microsoft Docs
ms.custom: 
ms.date: 09/04/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- WINVER in an upgraded Visual C++ project
- _WIN32_WINNT in an upgraded Visual C++ project
ms.assetid: 6a1f1d66-ae0e-48a7-81c3-524d8e8f3447
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 298fc14c57ad006228da39d1eb7d664debebd904
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="modifying-winver-and-win32winnt"></a>Modificando WINVER e _WIN32_WINNT

Visual C++ não oferece mais suporte ao direcionamento de Windows 95, Windows 98, Windows ME, Windows NT ou Windows 2000. Se suas macros **WINVER** ou **_WIN32_WINNT** forem atribuídas a uma dessas versões do Windows, você deverá modificar as macros. Quando você atualiza um projeto criado usando uma versão anterior do Visual C++, poderá ver erros de compilação relacionados às macros **WINVER** ou **_WIN32_WINNT** se elas forem atribuídas a uma versão do Windows que não tem mais suporte.  
  
## <a name="remarks"></a>Comentários  

Para modificar as macros, em um arquivo de cabeçalho (por exemplo, targetver.h que é incluído quando você cria um projeto que tem como alvo Windows), adicione as seguintes linhas.  
  
```C  
#define WINVER 0x0A00  
#define _WIN32_WINNT 0x0A00  
```  
  
Isso direciona o sistema operacional Windows 10. Esses valores são listados no arquivo de cabeçalho do Windows SDKDDKVer.h, que também define as macros para cada versão do Windows. Você deve adicionar a instrução #define antes de incluir SDKDDKVer.h. Aqui estão as linhas da versão do Windows 10 do SDKDDKVer.h que codificam os valores para cada versão do Windows:  
  
```C  
//  
// _WIN32_WINNT version constants  
//  
#define _WIN32_WINNT_NT4                    0x0400 // Windows NT 4.0  
#define _WIN32_WINNT_WIN2K                  0x0500 // Windows 2000  
#define _WIN32_WINNT_WINXP                  0x0501 // Windows XP  
#define _WIN32_WINNT_WS03                   0x0502 // Windows Server 2003  
#define _WIN32_WINNT_WIN6                   0x0600 // Windows Vista  
#define _WIN32_WINNT_VISTA                  0x0600 // Windows Vista  
#define _WIN32_WINNT_WS08                   0x0600 // Windows Server 2008  
#define _WIN32_WINNT_LONGHORN               0x0600 // Windows Vista  
#define _WIN32_WINNT_WIN7                   0x0601 // Windows 7  
#define _WIN32_WINNT_WIN8                   0x0602 // Windows 8  
#define _WIN32_WINNT_WINBLUE                0x0603 // Windows 8.1  
#define _WIN32_WINNT_WINTHRESHOLD           0x0A00 // Windows 10  
#define _WIN32_WINNT_WIN10                  0x0A00 // Windows 10  
```  
  
Se você não vir todas essas versões do Windows listadas em uma cópia do SDKDDKVer.h sendo visualizada, você provavelmente estará usando uma versão mais antiga do SDK do Windows. Por padrão, os projetos do Win32 no Visual Studio 2017 usam o SDK do Windows 10.   
  
> [!NOTE]
>  Os valores não têm garantia de funcionamento se você incluir cabeçalhos MFC internos em seu aplicativo.  
  
Também é possível definir essa macro usando a opção do compilador **/D**. Para obter mais informações, consulte [/D (definições de pré-processador)](../build/reference/d-preprocessor-definitions.md).  
  
Para obter mais informações sobre os significados dessas macros, consulte [Using the Windows Headers](https://msdn.microsoft.com/library/windows/desktop/aa383745) (Usando os cabeçalhos do Windows).  
  
## <a name="see-also"></a>Consulte também  

[Histórico de alterações do Visual C++](..\porting\visual-cpp-change-history-2003-2015.md)
