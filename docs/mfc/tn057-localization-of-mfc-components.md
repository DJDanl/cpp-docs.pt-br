---
title: "TN057: Localização de componentes MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e27b737a76b30e7193a9afb7797a20951294032e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn057-localization-of-mfc-components"></a>TN057: localização de componentes MFC
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve alguns dos designs e procedimentos que você pode usar para localizar seu componente, se ele controla uma OLE ou um aplicativo ou uma DLL que usa MFC.  
  
## <a name="overview"></a>Visão geral  
 Há dois problemas para resolver quando realmente Localizando um componente que usa MFC. Primeiro, você deve localizar seus próprios recursos — cadeias de caracteres, caixas de diálogo e outros recursos que são específicos para o seu componente. A maioria dos componentes desenvolvidos utilizando o MFC também incluem e usam uma série de recursos que são definidos pelo MFC. Você deve fornecer recursos localizados do MFC também. Felizmente, vários idiomas já são fornecidos pelo MFC em si.  
  
 Além disso, o componente deve estar preparado para executar em seu ambiente de destino (ambiente Europeu ou DBCS-habilitado). A maior parte do tempo, isso depende de seu aplicativo tratar caracteres com o conjunto de bit alto corretamente e manipulação de cadeias de caracteres com caracteres de byte duplo. MFC está habilitado, por padrão, para esses ambientes, é possível ter um único binário mundial que é usado em todas as plataformas com diferentes apenas recursos conectados no momento da instalação.  
  
## <a name="localizing-your-components-resources"></a>Localizando recursos do componente  
 Localizar o aplicativo ou a DLL deve envolver simplesmente substituindo os recursos com recursos que corresponda ao idioma de destino. Para seus próprios recursos, isso é relativamente simple: editar os recursos no editor de recurso e criar seu aplicativo. Se seu código é escrito corretamente, não haverá nenhum cadeias de caracteres ou o texto que você deseja localizar embutido no código-fonte C++ - localização todos pode ser feito modificando simplesmente recursos. Na verdade, você pode implementar seu componente, de modo que todos os fornecer uma versão localizada não envolve até mesmo uma compilação do código original. Isso é mais complexo, mas é vale a pena e é o mecanismo escolhido para MFC em si. Também é possível localizar um aplicativo ao carregar o arquivo EXE ou DLL para o editor de recurso e editando os recursos diretamente. Ao possíveis, ele exige reaplicação essas alterações sempre que você cria uma nova versão do seu aplicativo.  
  
 Uma maneira de evitar que é localizar todos os recursos em uma DLL separada, às vezes chamada de uma DLL satélite. Esta DLL é carregada, em seguida, dinamicamente em tempo de execução e os recursos são carregados por essa DLL em vez do módulo principal com todo o seu código. MFC oferece suporte diretamente a essa abordagem. Considere um aplicativo chamado MYAPP. EXE; ele pode ter todos os seus recursos localizados em uma DLL chamada MYRES. DLL. O aplicativo `InitInstance` ele executará o seguinte para carregar essa DLL e causar MFC carregar recursos de local:  
  
```  
CMyApp::InitInstance()  
{ *// one of the first things in the init code  
    HINSTANCE hInst = LoadLibrary("myres.dll");

    if (hInst != NULL)  
    AfxSetResourceHandle(hInst);

 *// other initialization code would follow  
 .  
 .  
 .  
}  
```  
  
 Daí em seguida diante, MFC carregará recursos dessa DLL em vez de myapp.exe. Todos os recursos, no entanto, devem estar presentes nessa DLL; MFC não irá procurar a instância do aplicativo em busca de um determinado recurso. Essa técnica se aplica igualmente bem para regular MFC DLLs, bem como os controles OLE. Copie a versão apropriada do MYRES o programa de instalação. Dependendo da localidade quais recursos DLL que o usuário.  
  
 É relativamente fácil de criar um recurso somente DLL. Criar um projeto de DLL, adicione sua. RC para ele e adicione os recursos necessários. Se você tiver um projeto existente que não usa essa técnica, você pode copiar os recursos de projeto. Depois de adicionar o arquivo de recurso para o projeto, você está quase pronto para compilar o projeto. A única coisa que você deve fazer é definir as opções para incluir o vinculador **/NOENTRY**. Isso informa o vinculador que a DLL não tem nenhum ponto de entrada - desde que ele não tem código, ele não tem nenhum ponto de entrada.  
  
> [!NOTE]
>  O editor de recurso no Visual C++ 4.0 e posterior oferece suporte a vários idiomas por. Arquivo RC. Isso pode tornar fácil gerenciar sua localização em um único projeto. Os recursos de cada idioma são controlados por diretivas de pré-processador geradas pelo editor de recurso.  
  
## <a name="using-the-provided-mfc-localized-resources"></a>Usando o MFC fornecido recursos localizados  
 Qualquer aplicativo do MFC que você criar reutiliza duas coisas de MFC: código e recursos. Ou seja, MFC tem várias mensagens de erro, caixas de diálogo internas e outros recursos que são usados pelas classes MFC. Para localizar completamente o seu aplicativo, você precisa localizar não apenas recursos de seu aplicativo, mas também os recursos que são fornecidos diretamente do MFC. MFC fornece um número de idiomas diferentes arquivos de recursos automaticamente, para que se o idioma de que destino for um dos idiomas que MFC já oferece suporte, você só precisa fazer se que você usar esses recursos localizados.  
  
 Redação deste artigo, o MFC oferece suporte a chinês, alemão, espanhol, francês, italiano, japonês e coreano. Os arquivos que contêm essas versões localizadas estão no MFC\INCLUDE\L.* (o L significa para as versões localizadas) diretórios. Os arquivos alemão estão em MFC\INCLUDE\L.DEU, por exemplo. Para fazer com que seu aplicativo para usar esses arquivos RC em vez dos arquivos localizados em MFC\INCLUDE, adicione um `/IC:\PROGRAM FILES\MICROSOFT VISUAL STUDIO .NET 2003\VC7\MFC\INCLUDE\L.DEU` a linha de comando RC (Isso é apenas um exemplo; você precisa substituir sua localidade de opção, bem como o diretório em que você instalou o Visual C# ++).  
  
 As instruções acima funcionará se seu aplicativo estiver vinculado estaticamente com MFC. A maioria dos aplicativos vincular dinamicamente (porque esse é o padrão de AppWizard). Neste cenário, não apenas o código está dinamicamente vinculado -, portanto, são os recursos. Como resultado, você pode localizar os recursos em seu aplicativo, mas os recursos de implementação MFC ainda serão carregados do MFC7x.DLL (ou posterior) ou de MFC7xLOC.DLL se ele existir. Você pode abordar isso de duas diferentes ângulos.  
  
 A abordagem mais complexa é enviar um o MFC7xLOC.DLLs localizada (como MFC7xDEU, para o alemão, MFC7xESP.DLL para espanhol, etc.) ou uma versão posterior e instalar o MFC7xLOC.DLL apropriado para o diretório do sistema quando o usuário instala o aplicativo. Isso pode ser muito complexo para o desenvolvedor e o usuário final e como tal, não é recomendado. Consulte [56 de observação técnica](../mfc/tn056-installation-of-localized-mfc-components.md) para obter mais informações sobre essa técnica e suas limitações.  
  
 É a abordagem mais simples e segura incluir os recursos localizados do MFC em seu aplicativo ou a DLL em si (ou seu DLL se você estiver usando um satélite). Isso evita problemas de instalação MFC7xLOC.DLL corretamente. Para fazer isso, siga as mesmas instruções para o caso estático acima (configuração de linha de comando RC corretamente para apontar para os recursos localizados), exceto que você também deve remover o `/D_AFXDLL` definir que foi adicionado pelo AppWizard. Quando `/D_AFXDLL` é definida, AFXRES. H (e outros arquivos MFC RC) não realmente definir todos os recursos (porque eles serão recebidos de DLLs MFC em vez disso).  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

