---
title: Requisitos de build para controles comuns do Windows Vista
ms.date: 11/04/2016
helpviewer_keywords:
- common controls (MFC), build requirements
- common controls (MFC)
ms.assetid: 025f7d55-55a2-4dcd-8f62-02424e3dcc04
ms.openlocfilehash: 1a2e79d91a41ea178eeb6f74ec7fa7b22588b277
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386246"
---
# <a name="build-requirements-for-windows-vista-common-controls"></a>Requisitos de build para controles comuns do Windows Vista

A biblioteca Microsoft Foundation Class (MFC) oferece suporte à versão de controles comuns do Windows 6.1. Os controles comuns são incluídos no Windows Vista e a biblioteca é incluída no SDK do Visual Studio. A biblioteca fornece novos métodos que melhoram a classes existentes e novas classes e métodos que oferecem suporte a controles comuns do Windows Vista. Quando você compila seu aplicativo, você deve seguir os requisitos de migração e de compilação que são descritos nas seções a seguir.

## <a name="compilation-requirements"></a>Requisitos de compilação

### <a name="supported-versions"></a>Versões com suporte

Algumas novas classes e métodos dão suporte somente o Windows Vista e posterior, enquanto outros métodos também dão suporte a sistemas operacionais anteriores. Uma observação no `Requirements` seção de cada tópico do método Especifica quando o mínimo necessário de sistema operacional é Windows Vista.

Mesmo se o computador não executa o Windows Vista, você pode criar um aplicativo do MFC que serão executados no Windows Vista, se você tiver arquivos de cabeçalho MFC versão 6.1 em seu computador. No entanto, controles comuns que são projetados especificamente para o Windows Vista funcionam somente no sistema e são ignorados pelos sistemas operacionais anteriores.

### <a name="supported-character-sets"></a>Conjuntos de caracteres com suporte

Os novos controles comuns do Windows dão suporte a apenas o conjunto de caracteres Unicode e não o conjunto de caracteres ANSI. Se você compilar seu aplicativo na linha de comando, use os dois seguintes definem (/ 1!d) conjunto de caracteres de opções do compilador para especificar Unicode como subjacente:

```
/D_UNICODE /DUNICODE
```

Se você compilar seu aplicativo no ambiente de desenvolvimento integrado (IDE) do Visual Studio, especifique o **conjunto de caracteres Unicode** opção do **conjunto de caracteres** propriedade no **geral**  nó das propriedades do projeto.

A versão ANSI de vários métodos MFC foram preteridas começando com a versão 6.1 controles comuns do Windows. Para obter mais informações, consulte [preteridos ANSI APIs](../mfc/deprecated-ansi-apis.md).

## <a name="migration-requirements"></a>Requisitos de migração

Se você usar o IDE do Visual Studio para criar um novo aplicativo do MFC que usa controles comuns do Windows versão 6.1, o IDE declara automaticamente um manifesto apropriado. No entanto, se você migra um aplicativo MFC existente de uma versão anterior do Visual Studio e você deseja usar os novos controles comuns, o IDE não automaticamente fornece informações de manifesto para atualizar seu aplicativo. Em vez disso, é necessário inserir manualmente o seguinte código-fonte no seu **Stdafx. h** arquivo:

```
#ifdef UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif
```

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)<br/>
[Gráfico da hierarquia](../mfc/hierarchy-chart.md)<br/>
[APIs ANSI preteridas](../mfc/deprecated-ansi-apis.md)
