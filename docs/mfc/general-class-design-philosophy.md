---
title: Filosofia de design da classe geral
ms.date: 11/04/2016
helpviewer_keywords:
- designing classes [MFC]
- MFC, Windows API
- Visual C, Windows API calls
- classes [MFC], MFC class design
- Windows API [MFC], and MFC
ms.assetid: e6861ae0-1581-4d9c-9ddf-63f9afcdb913
ms.openlocfilehash: cfad635c2a826c6f57e2e1513d753a4083494dee
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618779"
---
# <a name="general-class-design-philosophy"></a>Filosofia de design da classe geral

O Microsoft Windows foi projetado muito antes que a linguagem C++ se tornou popular. Como milhares de aplicativos usam a API (interface de programação de aplicativo) do Windows em linguagem C, essa interface será mantida para o futuro próximo. Qualquer interface C++ do Windows deve, portanto, ser criada sobre o procedimento da API C-Language. Isso garante que os aplicativos C++ poderão coexistir com os aplicativos C.

O biblioteca MFC é uma interface orientada a objeto para o Windows que atende às seguintes metas de design:

- Redução significativa no esforço para escrever um aplicativo para o Windows.

- Velocidade de execução comparável à da API de linguagem C.

- Sobrecarga mínima do tamanho do código.

- Capacidade de chamar qualquer função do Windows C diretamente.

- Conversão mais fácil de aplicativos C existentes em C++.

- Capacidade de aproveitar a base existente da experiência de programação do Windows em linguagem C.

- Uso mais fácil da API do Windows com C++ do que com C.

- Abstrações mais fáceis de usar, porém, poderosas de recursos complicados, como controles ActiveX, suporte a banco de dados, impressão, barras de ferramentas e barras de status.

- A verdadeira API do Windows para C++ que usa efetivamente os recursos da linguagem C++.

Para obter mais informações sobre o design da biblioteca do MFC, consulte:

- [A estrutura do aplicativo](application-framework.md)

- [Relação com a API C-Language](relationship-to-the-c-language-api.md)

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
