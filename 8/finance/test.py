from sqlalchemy import Column, ForeignKey, Integer, String,Float
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import relationship
from sqlalchemy import create_engine
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

Base=declarative_base()
class User(Base):
    __tablename__="users"
    id=Column(Integer,primary_key=True,autoincrement=True)
    username=Column(String(250),nullable=False)
    hash=Column(String(250),nullable=False)
    cash=Column(Float,default=1000)

class Shares(Base):
   __tablename__="shares"
   name=Column(String(250),nullable=False)
   number=Column(Integer,default=0)
   owerid=Column(Integer)
   id=Column(Integer,default=0,primary_key=True,autoincrement=True)
   price=Column(Float,default=0)


engine = create_engine('sqlite:///finance.db')
Base.metadata.bind=engine
DBSession = sessionmaker(bind = engine)
dbsession = DBSession()
#cylshares is an list of instance of Shares
cylshares = dbsession.query(Shares).filter_by(owerid=2)

print(cylshares[0].name)
print(cylshares[1].name)


Base.metadata.create_all(engine)