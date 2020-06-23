---
title: Atualizar WINVER e _WIN32_WINNT
description: Quando e como atualizar macros WINVER e _WIN32_WINNT em projetos do Visual Studio C++ atualizados.
ms.date: 06/19/2020
helpviewer_keywords:
- WINVER in an upgraded Visual Studio C++ project
- _WIN32_WINNT in an upgraded Visual Studio C++ project
ms.assetid: 6a1f1d66-ae0e-48a7-81c3-524d8e8f3447
ms.openlocfilehash: a0faed612517bf26cd89473e1aef248fb9e7b33e
ms.sourcegitcommit: 493fd8747f832e1facb9a76c437a25a5c9fb55f6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/22/2020
ms.locfileid: "85141048"
---
# <a name="update-winver-and-_win32_winnt"></a>Atualizar WINVER e _WIN32_WINNT

Ao usar o SDK do Windows, você pode especificar em quais versões do Windows seu código pode ser executado. As macros de pré-processador **winver** e **_WIN32_WINNT** especificam a versão mínima do sistema operacional com suporte do seu código. O Visual Studio e o compilador do Microsoft C++ dão suporte ao Windows 7 SP1 e posterior. Os conjuntos de ferramentas mais antigos incluem suporte para o Windows XP SP2, o Windows Server 2003 SP1, o Vista e o Windows Server 2008. Não há suporte para o Windows 95, Windows 98, Windows ME, Windows NT e Windows 2000.

Ao atualizar um projeto mais antigo, talvez seja necessário atualizar suas macros **winver** ou **_WIN32_WINNT** . Se eles forem atribuídos a valores para uma versão sem suporte do Windows, você poderá ver erros de compilação relacionados a essas macros.

## <a name="remarks"></a>Comentários

Para modificar as macros, em um arquivo de cabeçalho (por exemplo, em *targetver. h*, que é incluído por alguns modelos de projeto que se destinam ao Windows), adicione as linhas a seguir.

```C
#define WINVER 0x0A00
#define _WIN32_WINNT 0x0A00
```

As macros no exemplo são definidas para direcionar todas as versões do sistema operacional Windows 10. Os valores possíveis são listados no arquivo de cabeçalho do Windows *sdkddkver. h*, que define as macros para cada versão principal do Windows. Para criar seu aplicativo para dar suporte a uma plataforma anterior do Windows, inclua *WinSDKVer. h*. Em seguida, defina as macros **winver** e **_WIN32_WINNT** para a plataforma com suporte mais antiga antes de incluir *sdkddkver. h*. Aqui estão as linhas da versão do SDK do Windows 10 do *sdkddkver. h* que codificam os valores para cada versão principal do Windows:

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

Para obter uma abordagem mais refinada ao controle de versão, você pode usar as constantes da versão NTDDI em *sdkddkver. h*. Aqui estão algumas das macros definidas por *sdkddkver. h* no Windows 10 SDK versão 10.0.18362.0:

```C
//
// NTDDI version constants
//
#define NTDDI_WIN7                          0x06010000
#define NTDDI_WIN8                          0x06020000
#define NTDDI_WINBLUE                       0x06030000
#define NTDDI_WINTHRESHOLD                  0x0A000000  /* ABRACADABRA_THRESHOLD */
#define NTDDI_WIN10                         0x0A000000  /* ABRACADABRA_THRESHOLD */
#define NTDDI_WIN10_TH2                     0x0A000001  /* ABRACADABRA_WIN10_TH2 */
#define NTDDI_WIN10_RS1                     0x0A000002  /* ABRACADABRA_WIN10_RS1 */
#define NTDDI_WIN10_RS2                     0x0A000003  /* ABRACADABRA_WIN10_RS2 */
#define NTDDI_WIN10_RS3                     0x0A000004  /* ABRACADABRA_WIN10_RS3 */
#define NTDDI_WIN10_RS4                     0x0A000005  /* ABRACADABRA_WIN10_RS4 */
#define NTDDI_WIN10_RS5                     0x0A000006  /* ABRACADABRA_WIN10_RS5 */
#define NTDDI_WIN10_19H1                    0x0A000007  /* ABRACADABRA_WIN10_19H1*/

#define WDK_NTDDI_VERSION                   NTDDI_WIN10_19H1 /* ABRACADABRA_WIN10_19H1 */

//
// masks for version macros
//
#define OSVERSION_MASK      0xFFFF0000
#define SPVERSION_MASK      0x0000FF00
#define SUBVERSION_MASK     0x000000FF

//
// macros to extract various version fields from the NTDDI version
//
#define OSVER(Version)  ((Version) & OSVERSION_MASK)
#define SPVER(Version)  (((Version) & SPVERSION_MASK) >> 8)
#define SUBVER(Version) (((Version) & SUBVERSION_MASK) )
```

As macros **OSVER**, **SPVER**e **SUBVER** podem ser usadas em seu código para controlar a compilação condicional para diferentes níveis de suporte de API.

Talvez você não veja todas essas versões do Windows listadas no *sdkddkver. h* que você está vendo. Isso significa que você provavelmente está usando uma versão mais antiga do SDK do Windows. Por padrão, novos projetos do Windows no Visual Studio usam o SDK do Windows 10.

> [!NOTE]
> Os valores não têm garantia de funcionamento se você incluir cabeçalhos MFC internos em seu aplicativo.

Também é possível definir essa macro usando a opção de compilador `/D`. Para obter mais informações, consulte [/D (definições de pré-processador)](../build/reference/d-preprocessor-definitions.md).

Para obter mais informações sobre os significados dessas macros, consulte [Using the Windows Headers](/windows/win32/WinProg/using-the-windows-headers) (Usando os cabeçalhos do Windows).

## <a name="see-also"></a>Veja também

[Histórico de alterações do Visual C++](../porting/visual-cpp-change-history-2003-2015.md)
