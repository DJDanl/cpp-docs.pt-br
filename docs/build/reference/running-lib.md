---
title: "Executando LIB | Microsoft Docs"
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
  - "VC.Project.VCLibrarianTool.TargetMachine"
  - "Lib"
  - "VC.Project.VCLibrarianTool.PrintProgress"
  - "VC.Project.VCLibrarianTool.SuppressStartupBanner"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos de comando /"
  - "opção de plataforma de destino /MACHINE"
  - "Opção /NOLOGO (gerenciador de biblioteca)"
  - "Opção /VERBOSE (gerenciador de biblioteca)"
  - "arquivos de comando de dois pontos [C++]"
  - "arquivos de comando"
  - "arquivos de comando, LIB"
  - "especificador de opção de traço"
  - "especificador de opção de barra"
  - "LIB [C++], executando LB"
  - "opção de plataforma de destino MACHINE"
  - "opção de plataforma de destino -MACHINE"
  - "opção de gerenciador de biblioteca NOLOGO"
  - "opção de gerenciador de biblioteca -NOLOGO"
  - "ponto e vírgula, arquivos de comando"
  - "barra (/)"
  - "opção de gerenciador de biblioteca VERBOSE"
  - "opção de gerenciador de biblioteca -VERBOSE"
ms.assetid: d54f5c81-7147-4b2c-a8db-68ce6eb1eabd
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Executando LIB
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As várias opções de linha de comando podem ser usadas para controlar o LIB.  
  
## Linha de comando de LIB  
 Para executar o LIB, digite o comando `lib` seguido pelas opções e os nomes de arquivo para a tarefa que você está usando o LIB para executar.  O LIB também aceita a linha de comando entrada nos arquivos de comando, que são descritas na seção.  O LIB não usar uma variável de ambiente.  
  
> [!NOTE]
>  Se você estiver acostumado as ferramentas de LINK32.exe e de LIB32.exe fornecidas com o software development kit\) do Microsoft Win32 para Windows NT, você pode usar o comando `link32 -lib` ou o comando `lib32` gerenciando bibliotecas e criar bibliotecas de importação.  Certifique\-se de alterar seus makefiles e arquivos em lote para usar o comando em vez de `lib` .  
  
## Arquivos de comando de LIB  
 Você pode passar argumentos de linha de comando ao LIB em um arquivo de comando usando a seguinte sintaxe:  
  
```  
LIB @commandfile  
```  
  
 O arquivo `commandfile` é um arquivo de texto.  Nenhum espaço ou a guia são permitidos entre o sinal de arroba \(@\) e o nome do arquivo.  Não há nenhuma extensão padrão; você deve especificar o nome de arquivo completo, incluindo qualquer extensão.  Os curingas não podem ser usadas.  Você pode especificar um caminho relativo ou absoluto um com o nome do arquivo.  
  
 No arquivo de comando, os argumentos podem ser separados por espaços ou por guias, como também na linha de comando; também podem ser separados por caracteres de nova linha.  Use um ponto\-e\-vírgula \(;\) para marcar um comentário.  O LIB ignora qualquer texto do ponto\-e\-vírgula ao final da linha.  
  
 Você pode especificar um ou outro todo ou parte de linha de comando em um arquivo de comando, e você pode usar mais de um arquivo de comando em um comando de LIB.  O LIB aceita comando\- Arquivo conectado como se fosse especificado naquele local na linha de comando.  Os arquivos de comando não podem ser aninhados.  O LIB ecoa o conteúdo dos arquivos de comando a menos que a opção \/NOLOGO é usada.  
  
## Usando opções de LIB  
 Uma opção consiste em um especificador da opção, que é um traço \(–\) ou uma barra \(\/\), seguido pelo nome da opção.  Os nomes de opção não podem ser abreviados.  Algumas opções possuem um argumento especificado, depois de dois\-pontos \(:\).  Nenhum espaço ou a guia são permitidos em uma especificação da opção.  Use um ou mais espaços ou guias para separar especificações de opção na linha de comando.  Os nomes da opção e seus argumentos da palavra\-chave ou nome de arquivo não diferenciam maiúsculas de minúsculas, mas os identificadores usados como argumentos diferenciam maiúsculas de minúsculas.  O LIB processa opções na ordem especificada na linha de comando e arquivos de comando.  Se uma opção é repetida com argumentos diferentes, o último a ser processado terá precedência.  
  
 As opções a seguir se aplicam a todos os modos de LIB:  
  
 \/ERRORREPORT \[NONE &#124; AVISO &#124; QUEUE &#124; SEND\]  
 Se lib.exe falha em tempo de execução, você pode usar \/ERRORREPORT para enviar informações à Microsoft sobre esses erros internos.  
  
 Para obter mais informações sobre como \/ERRORREPORT, consulte [\/errorReport \(erros de compilador internos do relatório\)](../Topic/-errorReport%20\(Report%20Internal%20Compiler%20Errors\).md).  
  
 \/LTCG  
 Faz com que a biblioteca a ser criada usando a geração de código de link\- Horas.  Para obter mais informações, consulte [\/LTCG](../../build/reference/ltcg-link-time-code-generation.md).  
  
 \/MACHINE  
 Especifica a plataforma de destino para o programa.  Em geral, você não precisa especificar \/MACHINE.  O LIB infere o tipo de computador dos arquivos de .obj.  Entretanto, em algumas circunstâncias, o LIB não pode determinar o tipo de computador e não emite uma mensagem de erro.  Se esse erro ocorrer, especifique \/MACHINE.  No modo de \/EXTRACT, essa opção é somente para verificação.  O uso `lib /?` na linha de comando considerar disponível no computador.  
  
 \/NOLOGO  
 Suprime a exibição da mensagem e o número de versão de direitos autorais de LIB e evita o eco de arquivos de comando.  
  
 \/VERBOSE  
 Detalhes das exibe informações sobre o progresso da sessão, incluindo nomes dos arquivos de .obj que está sendo adicionado.  A informação é enviada à saída padrão e pode ser orientada novamente para um arquivo.  
  
 \/WX \[: NOT\]  
 Avisos de serem tratados como erros.  Consulte [\/WX \(tratar avisos do vinculador como erros\)](../../build/reference/wx-treat-linker-warnings-as-errors.md) para maiores informações.  
  
 Outras opções se aplicam apenas aos modos de LIB específicos.  Essas opções são discutidas nas seções a seguir descrevem cada modo.  
  
## Consulte também  
 [Referência LIB](../../build/reference/lib-reference.md)