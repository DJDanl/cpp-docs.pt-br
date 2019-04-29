---
title: Filosofia de design da classe geral
ms.date: 11/04/2016
f1_keywords:
- vc.classes.mfc
helpviewer_keywords:
- designing classes [MFC]
- MFC, Windows API
- Visual C, Windows API calls
- classes [MFC], MFC class design
- Windows API [MFC], and MFC
ms.assetid: e6861ae0-1581-4d9c-9ddf-63f9afcdb913
ms.openlocfilehash: 4dfa11c73703f5f2d3d17f8278610d32178af679
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62219613"
---
# <a name="general-class-design-philosophy"></a>Filosofia de design da classe geral

Microsoft Windows foi projetado muito antes que a linguagem C++ se tornou popular. Como milhares de aplicativos usam a interface de programação de aplicativo (API) do Windows da linguagem C, essa interface será mantida no futuro. Nenhuma interface do Windows C++, portanto, deve ser criado sobre a API de linguagem C de procedimentos. Isso garante que aplicativos C++ seja capazes de coexistir com aplicativos C.

A biblioteca Microsoft Foundation Class é uma interface orientada a objeto para o Windows que cumpra as metas de design a seguir:

- Redução significativa no esforço necessário para escrever um aplicativo para Windows.

- Velocidade de execução comparável da linguagem C API.

- Sobrecarga de tamanho mínimo de código.

- Capacidade de chamar qualquer função de C do Windows diretamente.

- Conversão simplificada dos aplicativos existentes de C para C++.

- Capacidade de aproveitar da base existente do Windows da linguagem C experiência em programação.

- Facilitar o uso da API do Windows com C++ do que com C.

- Mais fácil e ainda usar abstrações poderosos do complicado recursos, como controles ActiveX, suporte de banco de dados, impressão, as barras de ferramentas e barras de status.

- True a API do Windows para C++ que usa com eficiência os recursos da linguagem C++.

Para obter mais informações sobre o design da biblioteca MFC, consulte:

- [A estrutura de aplicativo](../mfc/application-framework.md)

- [Relacionamento com a API da linguagem C](../mfc/relationship-to-the-c-language-api.md)

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
