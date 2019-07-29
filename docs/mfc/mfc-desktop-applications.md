---
title: Aplicativos para desktop do MFC
ms.date: 07/28/2019
f1_keywords:
- MFC
- mfc
helpviewer_keywords:
- libraries, MFC
- class libraries, MFC
- MFC, about MFC
ms.assetid: 7101cb18-a681-495c-8f2b-069ad20c72f7
ms.openlocfilehash: f23a41a0dbaedb7063617accee3afe4ba833d59c
ms.sourcegitcommit: 720b74dddb1cdf4e570d55103158304ee1df81f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/29/2019
ms.locfileid: "68607530"
---
# <a name="mfc-desktop-applications"></a>Aplicativos para desktop do MFC

A biblioteca do Microsoft Foundation Class (MFC) fornece um wrapper orientado a objeto em grande parte das APIs do Win32 e COM. Embora possa ser usado para criar aplicativos de área de trabalho muito simples, ele é mais útil quando você precisa desenvolver interfaces de usuário mais complexas com vários controles. Você pode usar o MFC para criar aplicativos com interfaces de usuário no estilo do Office. Para obter a documentação sobre a própria plataforma Windows, consulte a [documentação do Windows](/windows/index). Para obter informações sobre a criação de C++ aplicativos do Windows no sem MFC, consulte [criar aplicativos do Windows para desktop usando a API do Win32](/windows/win32/index).

A referência do MFC aborda as classes, as funções globais, as variáveis globais e as macros que compõem o biblioteca MFC.

Os gráficos de hierarquia individuais incluídos em cada classe são úteis para localizar classes base. A referência do MFC geralmente não descreve as funções de membro herdadas ou os operadores herdados. Para obter informações sobre essas funções, consulte as classes base descritas nos diagramas de hierarquia.

A documentação de cada classe inclui uma visão geral de classe, um resumo de membro por categoria e tópicos para as funções de membro, operadores sobrecarregados e membros de dados.

Membros de classe pública e protegida são documentados somente quando normalmente são usados em programas de aplicativo ou classes derivadas. Consulte os arquivos de cabeçalho de classe para obter uma lista completa dos membros de classe.

> [!IMPORTANT]
>  As classes do MFC e seus membros não podem ser usados em aplicativos que são executados no ambiente de Windows Runtime.
>
>  As bibliotecas MFC (DLLs) para codificação de caracteres multibyte (MBCS) não são mais incluídas no Visual Studio, mas estão disponíveis como um complemento do Visual Studio. Para obter mais informações, consulte [complemento dll do MFC MBCS](mfc-mbcs-dll-add-on.md).

## <a name="in-this-section"></a>Nesta seção

[Conceitos](mfc-concepts.md)<br/>
Artigos conceituais sobre tópicos do MFC.

[Gráfico da hierarquia](hierarchy-chart.md)<br/>
Detalha visualmente as relações de classe na biblioteca de classes.

[Visão geral da classe](class-library-overview.md)<br/>
Lista as classes na biblioteca do MFC de acordo com a categoria.

[Explicações Passo a Passo](walkthroughs-mfc.md)<br/>
Contém artigos que orientam você pelas várias tarefas associadas aos recursos da biblioteca do MFC.

[Notas técnicas](mfc-technical-notes.md)<br/>
Fornece links para tópicos especializados, escritos pela equipe de desenvolvimento do MFC, na biblioteca de classes.

[Personalização para MFC](customization-for-mfc.md)<br/>
Fornece algumas dicas para personalizar seu aplicativo MFC.

[Classes](reference/mfc-classes.md)<br/>
Fornece links para as informações de arquivo de cabeçalho e para as classes do MFC.

[Classes internas](reference/internal-classes.md)<br/>
Usado internamente no MFC. Para fins de integridade, esta seção descreve essas classes internas, mas elas não se destinam a ser usadas diretamente no seu código.

[Macros e globais](reference/mfc-macros-and-globals.md)<br/>
Fornece links para as macros e funções globais na biblioteca do MFC.

[Estruturas, estilos, retornos de chamada e mapas de mensagem](reference/structures-styles-callbacks-and-message-maps.md)<br/>
Fornece links para estruturas, estilos, retornos de chamada e mapas de mensagem usados pela biblioteca do MFC.

[Assistentes e caixas de diálogo do MFC](reference/mfc-wizards-and-dialog-boxes.md)<br/>
Um guia para os recursos do Visual Studio para criar aplicativos MFC.

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
Como usar os arquivos de recurso para gerenciar dados estáticos da interface do usuário, como cadeias de caracteres da interface e o layout da caixa de diálogo.

## <a name="related-sections"></a>Seções relacionadas

[Categorias de gráfico da hierarquia](hierarchy-chart-categories.md)<br/>
Descreve o gráfico de hierarquia do MFC por categoria.

[Classes compartilhadas ATL/MFC](../atl-mfc-shared/atl-mfc-shared-classes.md)<br/>
Fornece links para classes que são compartilhadas entre MFC e ATL.

[Exemplos de MFC](../overview/visual-cpp-samples.md)<br/>
Fornece links para exemplos que demonstram como usar o MFC.

[Referência de bibliotecas do Visual C++](../standard-library/cpp-standard-library-reference.md)<br/>
Fornece links para várias bibliotecas fornecidas com Visual C++, incluindo ATL, MFC e OLE DB, biblioteca em tempo de execução do C e a biblioteca do padrão C++.

[Depurando no Visual Studio](/visualstudio/debugger/debugging-in-visual-studio)<br/>
Fornece links para usar o depurador do Visual Studio para corrigir erros de lógica em seu aplicativo ou procedimentos armazenados.

## <a name="see-also"></a>Consulte também

[MFC e ATL](mfc-and-atl.md)
