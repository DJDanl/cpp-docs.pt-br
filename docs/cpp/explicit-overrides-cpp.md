---
title: "Substitui&#231;&#245;es Expl&#237;citas (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes derivadas, funções virtuais"
  - "substituição explícita de função virtual"
  - "substituições explícitas de função virtual"
  - "substituição, Funções "
  - "funções virtuais, substituições explícitas"
ms.assetid: ee583234-5cda-4e90-b55e-3f9fbf079ced
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Substitui&#231;&#245;es Expl&#237;citas (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Se a mesma função virtual é declarada em duas ou mais [interfaces](../Topic/__interface.md) e se uma classe for derivada dessas interfaces, você pode substituir explicitamente cada função virtual.  
  
 Para obter informações sobre as substituições explícitas em código gerenciado usando a nova sintaxe gerenciada, consulte [Substituições explícitas](../windows/explicit-overrides-cpp-component-extensions.md).  
  
 **FIM de Específico da Microsoft**  
  
## Exemplo  
 O exemplo de código a seguir ilustra como usar as substituições explícitas:  
  
```  
// deriv_ExplicitOverrides.cpp  
// compile with: /GR  
extern "C" int printf_s(const char *, ...);  
  
__interface IMyInt1 {  
   void mf1();  
   void mf1(int);  
   void mf2();  
   void mf2(int);  
};  
  
__interface IMyInt2 {  
   void mf1();  
   void mf1(int);  
   void mf2();  
   void mf2(int);  
};  
  
class CMyClass : public IMyInt1, public IMyInt2 {  
public:  
   void IMyInt1::mf1() {  
      printf_s("In CMyClass::IMyInt1::mf1()\n");  
   }  
  
   void IMyInt1::mf1(int) {  
      printf_s("In CMyClass::IMyInt1::mf1(int)\n");  
   }  
  
   void IMyInt1::mf2();  
   void IMyInt1::mf2(int);  
  
   void IMyInt2::mf1() {  
      printf_s("In CMyClass::IMyInt2::mf1()\n");  
   }  
  
   void IMyInt2::mf1(int) {  
         printf_s("In CMyClass::IMyInt2::mf1(int)\n");  
   }  
  
   void IMyInt2::mf2();  
   void IMyInt2::mf2(int);  
};  
  
void CMyClass::IMyInt1::mf2() {  
   printf_s("In CMyClass::IMyInt1::mf2()\n");  
}  
  
void CMyClass::IMyInt1::mf2(int) {  
   printf_s("In CMyClass::IMyInt1::mf2(int)\n");  
}  
  
void CMyClass::IMyInt2::mf2() {  
   printf_s("In CMyClass::IMyInt2::mf2()\n");  
}  
  
void CMyClass::IMyInt2::mf2(int) {  
   printf_s("In CMyClass::IMyInt2::mf2(int)\n");  
}  
  
int main() {  
   IMyInt1 *pIMyInt1 = new CMyClass();  
   IMyInt2 *pIMyInt2 = dynamic_cast<IMyInt2 *>(pIMyInt1);  
  
   pIMyInt1->mf1();  
   pIMyInt1->mf1(1);  
   pIMyInt1->mf2();  
   pIMyInt1->mf2(2);  
   pIMyInt2->mf1();  
   pIMyInt2->mf1(3);  
   pIMyInt2->mf2();  
   pIMyInt2->mf2(4);  
  
   // Cast to a CMyClass pointer so that the destructor gets called  
      CMyClass *p = dynamic_cast<CMyClass *>(pIMyInt1);  
      delete p;  
}  
```  
  
  **In CMyClass::IMyInt1::mf1\(\)**  
**In CMyClass::IMyInt1::mf1\(int\)**  
**In CMyClass::IMyInt1::mf2\(\)**  
**In CMyClass::IMyInt1::mf2\(int\)**  
**In CMyClass::IMyInt2::mf1\(\)**  
**In CMyClass::IMyInt2::mf1\(int\)**  
**In CMyClass::IMyInt2::mf2\(\)**  
**In CMyClass::IMyInt2::mf2\(int\)**   
## Consulte também  
 [Herança](../cpp/inheritance-cpp.md)