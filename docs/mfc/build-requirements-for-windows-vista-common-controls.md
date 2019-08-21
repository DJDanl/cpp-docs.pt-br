---
title: Requisitos de compilação para controles comuns do Windows
ms.date: 08/19/2019
helpviewer_keywords:
- Common Controls (MFC), build requirements
- Common Controls (MFC)
ms.assetid: 025f7d55-55a2-4dcd-8f62-02424e3dcc04
ms.openlocfilehash: 9ea90f95ba8e704cba5b22c5e7338659f0c5f033
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69630855"
---
# <a name="build-requirements-for-windows-common-controls"></a>Requisitos de compilação para controles comuns do Windows

A biblioteca do Microsoft Foundation Class (MFC) oferece suporte a [controles comuns do Windows](/windows/win32/controls/common-controls-intro). Os controles comuns são incluídos no Windows e a biblioteca é incluída no Visual Studio. A biblioteca do MFC fornece novos métodos que aprimoram as classes existentes, além de classes e métodos adicionais que dão suporte aos controles comuns do Windows. Ao criar seu aplicativo, você deve seguir os requisitos de compilação e migração descritos nas seções a seguir.

## <a name="compilation-requirements"></a>Requisitos de compilação

### <a name="supported-versions"></a>Versões com suporte

O MFC oferece suporte a todas as versões dos controles comuns. Para obter informações sobre versões de controles comuns do Windows, consulte [versões de controle comuns](/windows/win32/controls/common-control-versions).

### <a name="supported-character-sets"></a>Conjuntos de caracteres com suporte

Os controles comuns do Windows dão suporte apenas ao conjunto de caracteres Unicode e não ao conjunto de caracteres ANSI. Se você criar seu aplicativo na linha de comando, use as duas opções de compilador de definição a seguir (/D) para especificar o Unicode como o conjunto de caracteres subjacente:

```
/D_UNICODE /DUNICODE
```

Se você criar seu aplicativo no IDE (ambiente de desenvolvimento integrado) do Visual Studio, especifique a opção **conjunto de caracteres Unicode** da propriedade **conjunto de caracteres** no nó **geral** das propriedades do projeto.

## <a name="migration-requirements"></a>Requisitos de migração

Se você usar o IDE do Visual Studio para criar um novo aplicativo MFC que usa os controles comuns do Windows, o IDE declarará automaticamente um manifesto apropriado. No entanto, se você migrar um aplicativo MFC existente do Visual Studio 2005 ou anterior e quiser usar os controles comuns, o IDE não fornecerá automaticamente informações de manifesto para atualizar seu aplicativo. Em vez disso, você deve inserir manualmente o seguinte código-fonte em seu arquivo de cabeçalho pré-compilado:

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
