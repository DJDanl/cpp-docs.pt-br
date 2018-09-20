---
title: 'TN057: Localização de componentes MFC | Microsoft Docs'
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.components
dev_langs:
- C++
helpviewer_keywords:
- components [MFC], localizing
- TN057
- resources [MFC], localization
- localization [MFC], MFC resources
- localization [MFC], MFC components
- MFC DLLs [MFC], localizing
- DLLs [MFC], localizing MFC
- localization [MFC], resources
ms.assetid: 5376d329-bd45-41bd-97f5-3d895a9a0af5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8dcd3117d50d2d8905e5382cf226ba487c13a7c7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46414206"
---
# <a name="tn057-localization-of-mfc-components"></a>TN057: localização de componentes MFC

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve alguns dos designs e procedimentos que você pode usar para localizar seu componente, se ele controla uma OLE ou um aplicativo ou uma DLL que usa MFC.

## <a name="overview"></a>Visão geral

Há realmente dois problemas para resolver quando a localização de um componente que usa MFC. Primeiro, você deve localizar seus próprios recursos — cadeias de caracteres, as caixas de diálogo e outros recursos que são específicos para o seu componente. A maioria dos componentes criados usando o MFC também incluem e use um número de recursos que são definidos pelo MFC. Você deve fornecer os recursos localizados do MFC também. Felizmente, vários idiomas já são fornecidos pelo próprio MFC.

Além disso, o seu componente deve estar preparado para executar em seu ambiente de destino (ambiente Europa ou DBCS-habilitado). Geralmente, isso depende de seu aplicativo tratar caracteres com o conjunto de bits alto corretamente e manipulação de cadeias de caracteres com caracteres de byte duplo. MFC é habilitado, por padrão, para ambos os ambientes, que é possível ter um binário único internacional que é usado em todas as plataformas com apenas diferentes recursos conectados no momento da instalação.

## <a name="localizing-your-components-resources"></a>Localização de recursos do seu componente

Localização de seu aplicativo ou DLL deve envolver simplesmente substituindo os recursos com os recursos que correspondem ao idioma de destino. Para seus próprios recursos, isso é relativamente simples: editar os recursos no editor de recursos e compilar o aplicativo. Se seu código é escrito corretamente, haverá sem cadeias de caracteres ou texto que você deseja localizar embutidos no código-fonte C++ - localização de todos os pode ser feito modificando simplesmente recursos. Na verdade, você pode implementar seu componente, de modo que todos os fornecer uma versão localizada não envolve até mesmo uma compilação do código original. Isso é mais complexo, mas vale a pena- e é o mecanismo escolhido para o próprio MFC. Também é possível localizar um aplicativo carregando o arquivo EXE ou DLL em editor de recursos e editando os recursos diretamente. Embora seja possível, ele requer a reaplicação dessas alterações sempre que você cria uma nova versão do seu aplicativo.

Uma maneira de evitar isso é localizar todos os recursos em uma DLL separada, às vezes chamada de uma DLL satélite. Essa DLL, em seguida, é carregado dinamicamente em tempo de execução e os recursos são carregados de DLL em vez do módulo principal com todo o seu código. Diretamente, o MFC é compatível com essa abordagem. Considere um aplicativo chamado MYAPP. EXE; ele poderia ter todos os seus recursos localizados em uma DLL chamada MYRES. DLL. Na caixa de diálogo `InitInstance` ele executaria o seguinte para carregar essa DLL e fazer com que o MFC carregar recursos a partir desse local:

```cpp
CMyApp::InitInstance()
{
    // one of the first things in the init code
    HINSTANCE hInst = LoadLibrary("myres.dll");

    if (hInst != NULL)
        AfxSetResourceHandle(hInst);

    // other initialization code would follow
    // ...
}
```

Daí em seguida diante, o MFC será carregar recursos de DLL em vez do myapp.exe. Todos os recursos, no entanto, devem estar presentes na DLL; MFC não pesquisará a instância do aplicativo em busca de um determinado recurso. Essa técnica se aplica igualmente bem para regular DLLs do MFC, bem como controles OLE. Copie a versão apropriada do MYRES seu programa de instalação. Dependendo da localidade quais recursos DLL que o usuário.

É relativamente fácil criar um recurso somente de DLL. Criar um projeto de DLL, adicione sua. RC do arquivo a ela e adicione os recursos necessários. Se você tiver um projeto existente que não usa essa técnica, você pode copiar os recursos de projeto. Depois de adicionar o arquivo de recurso para o projeto, você está quase pronto para compilar o projeto. A única coisa que você deve fazer é definir o vinculador opções para incluir **/NOENTRY**. Isso instrui o vinculador que a DLL não tem nenhum ponto de entrada - uma vez que ele não tem nenhum código, ele não tem nenhum ponto de entrada.

> [!NOTE]
> O editor de recursos no Visual C++ 4.0 e posterior dá suporte a vários idiomas por. Arquivo RC. Isso pode tornar muito fácil de gerenciar sua localização em um único projeto. Os recursos de cada idioma são controlados pelas diretivas de pré-processador geradas pelo editor de recursos.

## <a name="using-the-provided-mfc-localized-resources"></a>Usar o MFC fornecido recursos localizados

Qualquer aplicativo do MFC que você crie reutiliza duas coisas do MFC: códigos e recursos. Ou seja, o MFC tem várias mensagens de erro, caixas de diálogo internas e outros recursos que são usados pelas classes do MFC. Para localizar completamente o seu aplicativo, você precisa localizar não apenas recursos de seu aplicativo, mas também os recursos que vêm diretamente do MFC. MFC fornece um número de idiomas diferentes arquivos de recurso automaticamente, para que se o idioma de que destino for um dos idiomas que MFC já oferece suporte, você só precisa fazer-se de que usar esses recursos localizados.

A partir da redação deste artigo, o MFC oferece suporte a chinês, alemão, espanhol, francês, italiano, japonês e coreano. Os arquivos que contêm essas versões localizadas estão no MFC\INCLUDE\L.* (o "L" significa para as versões localizadas) diretórios. Os arquivos de alemão estão em MFC\INCLUDE\L.DEU, por exemplo. Para fazer com que seu aplicativo para usar esses arquivos RC em vez dos arquivos localizados em MFC\INCLUDE, adicione um `/IC:\PROGRAM FILES\MICROSOFT VISUAL STUDIO .NET 2003\VC7\MFC\INCLUDE\L.DEU` para sua linha de comando RC (Isso é apenas um exemplo; você precisará substituir sua localidade de escolha, bem como o diretório no qual você instalou o Visual C ++).

As instruções acima funcionará se seu aplicativo se vincula estaticamente com o MFC. A maioria dos aplicativos vincular dinamicamente (pois esse é o padrão de AppWizard). Nesse cenário, não apenas o código está dinamicamente vinculado - portanto, são os recursos. Como resultado, você pode localizar os recursos em seu aplicativo, mas os recursos de implementação MFC ainda serão carregados do MFC7x.DLL (ou uma versão posterior) ou de MFC7xLOC.DLL se ele existir. Você pode abordar isso de duas diferentes ângulos.

A abordagem mais complexa é enviar um do MFC7xLOC.DLLs localizada (como MFC7xDEU para alemão, MFC7xESP.DLL para espanhol, etc.) ou uma versão posterior e instalar o MFC7xLOC.DLL apropriados no diretório do sistema quando o usuário instala o aplicativo. Isso pode ser muito complexo para o desenvolvedor e o usuário final e como tal, não é recomendado. Ver [56 de observação técnica](../mfc/tn056-installation-of-localized-mfc-components.md) para obter mais informações sobre essa técnica e suas advertências.

A abordagem mais simples e segura é incluir os recursos localizados do MFC em seu aplicativo ou DLL em si (ou sua DLL se você estiver usando uma de satélite). Isso evita os problemas de instalação MFC7xLOC.DLL corretamente. Para fazer isso, você siga as mesmas instruções para o caso estático fornecido acima (linha de comando RC corretamente para apontar para os recursos localizados a definição), exceto que você também deve remover o `/D_AFXDLL` definir que foi adicionado por AppWizard. Quando `/D_AFXDLL` é definido, AFXRES. H (e outros arquivos de MFC RC), na verdade, define todos os recursos (porque eles serão obtidos a partir de DLLs do MFC em vez disso).

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
