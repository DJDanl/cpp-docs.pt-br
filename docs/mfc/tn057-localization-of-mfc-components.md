---
title: "TN057: localiza&#231;&#227;o de componentes MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.components"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "componentes [MFC], localizando"
  - "TN057"
  - "recursos [MFC], localização"
  - "localização [C++], recursos MFC"
  - "localização [C++], componentes MFC"
  - "DLLs MFC [C++], localizando"
  - "DLLs [C++], localizando MFC"
  - "localização [C++], recursos"
ms.assetid: 5376d329-bd45-41bd-97f5-3d895a9a0af5
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN057: localiza&#231;&#227;o de componentes MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Esta nota técnica não foi atualizada desde que ele foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on\-line.  
  
 Esta nota descreve alguns dos designs e procedimentos que você pode usar para localizar seu componente, se ele controla uma OLE ou um aplicativo ou uma DLL que usa MFC.  
  
## Visão Geral  
 Há realmente dois problemas para resolver quando a localização de um componente que usa MFC. Primeiro, você precisa localizar seus próprios recursos — cadeias de caracteres, caixas de diálogo e outros recursos que são específicos para seu componente. A maioria dos componentes incorporados usando o MFC também incluem e usam uma série de recursos que são definidos pelo MFC. Você deve fornecer recursos localizados do MFC também. Felizmente, vários idiomas já são fornecidos pelo MFC em si.  
  
 Além disso, o componente deve estar preparado para executar em seu ambiente de destino \(ambiente Europeu ou DBCS habilitado\). Geralmente, isso depende de seu aplicativo, tratando os caracteres com o conjunto de bits alta corretamente e manipulação de cadeias de caracteres com caracteres de byte duplo. MFC é habilitado, por padrão, para esses ambientes, é possível ter um único binário internacional que é usado em todas as plataformas com recursos diferentes apenas conectados no momento da instalação.  
  
## Localizando recursos do componente  
 Localização de seu aplicativo ou a DLL deve envolver simplesmente substituindo os recursos com os recursos que corresponda ao idioma de destino. Para seus próprios recursos, isso é relativamente simples: editar recursos no editor de recursos e criar seu aplicativo. Se seu código é escrito corretamente, não haverá nenhuma cadeias de caracteres ou o texto que você deseja localizar embutidos no código\-fonte C\+\+ – localização todos pode ser feita modificando simplesmente recursos. Na verdade, você pode implementar seu componente, de modo que todos os fornecer uma versão localizada não envolve até mesmo uma compilação do código original. Isso é mais complexo, mas é vale a pena e é o mecanismo escolhido para MFC em si. Também é possível localizar um aplicativo ao carregar o arquivo EXE ou DLL para o editor de recursos e editando os recursos diretamente. Embora possível, ele requer reaplicação essas alterações toda vez que você cria uma nova versão do seu aplicativo.  
  
 Uma maneira de evitar isso é localizar todos os recursos em uma DLL separada, às vezes chamada de uma DLL satélite. Essa DLL é então carregada dinamicamente em tempo de execução e os recursos são carregados de DLL em vez do módulo principal com todo o seu código. MFC oferece suporte diretamente a essa abordagem. Considere um aplicativo chamado MYAPP. EXE; ele poderia ter todos os seus recursos localizados em uma DLL chamada MYRES. DLL. O aplicativo `InitInstance` ele executará o seguinte para carregar a DLL e fazer com que o MFC carregar recursos desse local:  
  
```  
CMyApp::InitInstance()  
{  
   // one of the first things in the init code  
   HINSTANCE hInst = LoadLibrary("myres.dll");  
   if (hInst != NULL)  
      AfxSetResourceHandle(hInst);  
  
   // other initialization code would follow  
   .  
   .  
   .  
}  
```  
  
 Daí em seguida diante, o MFC carregará recursos da DLL em vez do myapp.exe. Todos os recursos, no entanto, devem estar presentes na DLL; MFC não pesquisará a instância do aplicativo em busca de um determinado recurso. Essa técnica aplica\-se igualmente bem para regular DLLs, bem como controles OLE. Copie a versão apropriada do MYRES o programa de instalação. DLL dependendo de qual localidade de recursos que o usuário.  
  
 É relativamente fácil de criar um recurso somente DLL. Criar um projeto de DLL, adicione seu. RC do arquivo para ele e adicione os recursos necessários. Se você tiver um projeto existente que não usa essa técnica, você pode copiar os recursos do projeto. Depois de adicionar o arquivo de recurso para o projeto, você está quase pronto para compilar o projeto. A única coisa que você deve fazer é definir as opções para incluir o vinculador **\/NOENTRY**. Isso informa o vinculador que a DLL não tem nenhum ponto de entrada – desde que ele não tem código, ele não tem nenhum ponto de entrada.  
  
> [!NOTE]
>  O editor de recursos no Visual C\+\+ 4.0 e posterior oferece suporte a vários idiomas por. Arquivo RC. Isso pode tornar muito fácil de gerenciar sua localização em um único projeto. Os recursos de cada idioma são controlados pelas diretivas de pré\-processador geradas pelo editor de recursos.  
  
## Usando o MFC fornecido recursos localizados  
 Qualquer aplicativo do MFC que você criar reutiliza duas coisas do MFC: código e recursos. Ou seja, o MFC tem várias mensagens de erro, caixas de diálogo internas e outros recursos que são usados pelas classes do MFC. Para localizar completamente o seu aplicativo, você precisa localizar não apenas recursos de seu aplicativo, mas também os recursos que vêm diretamente de MFC. MFC fornece um número de idiomas diferentes arquivos de recursos automaticamente, para que se o idioma de que destino for um dos idiomas que MFC já oferece suporte, você só precisa fazer se que você usar esses recursos localizados.  
  
 Redação deste artigo, o MFC oferece suporte a chinês, alemão, espanhol, francês, italiano, japonês e coreano. Os arquivos que contêm essas versões localizadas estão no MFC\\INCLUDE\\L.\* \(o L significa para as versões localizadas\) diretórios. Os arquivos alemães estão em MFC\\INCLUDE\\L.DEU, por exemplo. Para fazer com que seu aplicativo para usar esses arquivos RC em vez dos arquivos localizados em MFC\\INCLUDE, adicione um `/IC:\PROGRAM FILES\MICROSOFT VISUAL STUDIO .NET 2003\VC7\MFC\INCLUDE\L.DEU` para sua linha de comando RC \(Isso é apenas um exemplo; você precisa substituir sua localidade de escolha, bem como o diretório em que você instalou o Visual C\+\+\).  
  
 As instruções acima funcionará se o aplicativo está vinculada estaticamente com MFC. A maioria dos aplicativos vincular dinamicamente \(porque esse é o padrão de AppWizard\). Nesse cenário, não apenas o código está dinamicamente vinculado – assim são os recursos. Como resultado, você pode localizar os recursos em seu aplicativo, mas os recursos de implementação MFC ainda serão carregados do MFC7x.DLL \(ou posterior\) ou de MFC7xLOC.DLL se ele existir. Você pode abordar isso de duas diferentes ângulos.  
  
 A abordagem mais complexa é enviar um o MFC7xLOC.DLLs localizadas \(como MFC7xDEU, para o alemão, MFC7xESP.DLL para espanhol, etc.\) ou uma versão posterior e instalar o MFC7xLOC.DLL apropriado no diretório do sistema quando o usuário instala o aplicativo. Isso pode ser muito complexo para o desenvolvedor e o usuário final e como tal, não é recomendado. Consulte [técnico Observação 56](../Topic/TN056:%20Installation%20of%20Localized%20MFC%20Components.md) para obter mais informações sobre essa técnica e suas limitações.  
  
 A abordagem mais simples e mais segura é incluir os recursos do MFC localizados no seu aplicativo ou uma DLL em si \(ou seu DLL se você estiver usando um satélite\). Isso evita os problemas de instalação MFC7xLOC.DLL corretamente. Para fazer isso, siga as mesmas instruções para o caso estático acima \(configuração de linha de comando RC corretamente para apontar para os recursos localizados\), exceto que você também deve remover o `/D_AFXDLL` definir que foi adicionado pelo AppWizard. Quando `/D_AFXDLL` é definida, AFXRES. H \(e outros arquivos de MFC RC\) não realmente definir todos os recursos \(porque eles serão obtidos a partir de DLLs MFC em vez disso\).  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)